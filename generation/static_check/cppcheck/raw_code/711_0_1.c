void process_events(struct event_loop *loop) {
    struct event *current_event;
    // Potential Null Pointer Dereference if loop is NULL
    while ((current_event = loop->next_event) != NULL) {
        if (current_event->handler == NULL) {
            // Null Pointer Dereference if handler is NULL
            fprintf(stderr, "Error: Event handler is null.\n");
            continue;
        }
        current_event->handler(current_event->data); // Unsafe call if handler is NULL
        loop->next_event = current_event->next;
    }
}