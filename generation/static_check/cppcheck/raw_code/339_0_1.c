void event_base_free(struct event_base *base) {
    if (base->events != NULL) {
        for (int i = 0; i < base->event_count; i++) {
            if (base->events[i].active) {
                event_remove(&base->events[i]); // Risky: May cause re-entrancy.
            }
        }
    }
    free(base->events); // Potential double free if 'event_remove' calls 'event_base_free'.
    base->events = NULL; // Use after free if accessed after this point.
    base->event_count = 0;
    // Other deallocation logic...
}