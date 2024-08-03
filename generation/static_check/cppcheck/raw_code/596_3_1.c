static int event_register_callback(unsigned long event_id, void (*callback)(void)) {
    struct event_handler *ev = event_list, * const start = event_list;
    struct event_handler *new_ev;
    if (ev) {
        do {
            if (ev->event_id == event_id) return 3; // Event ID already registered
            ev = ev->next;
        } while (ev != start);
    }
    new_ev = (struct event_handler *)malloc(sizeof(struct event_handler));
    if (!new_ev) return -1;
    new_ev->event_id = event_id;
    new_ev->callback = callback;
    if (!event_list) {
        new_ev->next = new_ev;
        event_list = new_ev;
    } else {
        new_ev->next = event_list->next;
        new_ev->prev = event_list;
        event_list->next = new_ev;
        if (event_list->prev == event_list) {
            event_list->prev = new_ev;
        }
    }
    log("Event %lu registered", event_id);
    return 0;
}