static void dispatch_timer_events(struct timer_base *base) {
    struct timer_event *tev;
    struct event_queue *timerq = NULL;
    int k;
    short repeat_count;

    for (k = 0; k < base->ntimerqueues; ++k) {
        if (!SIMPLEQ_EMPTY(base->timerqueues[k])) {
            timerq = base->timerqueues[k];
            break;
        }
    }
    assert(timerq != NULL);

    for (tev = SIMPLEQ_FIRST(timerq); tev; tev = SIMPLEQ_FIRST(timerq)) {
        if (tev->timer_flags & TIMER_REPEAT) {
            timer_queue_remove(base, tev, TIMERLIST_ACTIVE);
        } else {
            timer_event_free(tev); // Potential use-after-free if tev accessed after this point.
        }
        repeat_count = tev->timer_repeat;
        tev->timer_prepeat = &repeat_count;
        while (repeat_count) {
            repeat_count--;
            tev->timer_repeat = repeat_count;
            (*(tev->timer_callback))(tev->timer_id, tev->timer_data); // Vulnerable use.
            if (base->timer_break) return;
        }
    }
}

