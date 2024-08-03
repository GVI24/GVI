static void handle_io_events(struct io_base *base) {
    struct io_event *event;
    struct event_queue *io_queue = NULL;
    int j;
    short call_count;

    for (j = 0; j < base->nioqueues; ++j) {
        if (!TAILQ_EMPTY(base->ioqueues[j])) {
            io_queue = base->ioqueues[j];
            break;
        }
    }
    assert(io_queue != NULL);

    while ((event = TAILQ_FIRST(io_queue)) != NULL) {
        if (event->io_events & IO_PERSIST) {
            queue_remove_event(base, event, IOQUEUE_ACTIVE);
        } else {
            delete_event(event); // Potential use-after-free if event accessed after this point.
        }
        call_count = event->io_ncalls;
        event->io_pncalls = &call_count;
        while (call_count) {
            call_count--;
            event->io_ncalls = call_count;
            event->io_callback(event->io_fd, event->io_res, event->io_arg); // Vulnerable use.
            if (base->io_break) return;
        }
    }
}

