void initialize_event_handlers(struct event_base *base) {
    // Assume EVENT_MAX is the maximum number of different events
    for (int i = 0; i <= EVENT_MAX; ++i) { // Off-by-one error, should be i < EVENT_MAX
        base->event_handlers[i].callback = NULL;
        base->event_handlers[i].context = NULL;
    }
    // Rest of initialization code
}

