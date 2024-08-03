static void log_event(struct event *evt, struct log *event_log, int *log_index) {
    int index;
    index = find_event_log_position(event_log, evt->id);
    if (index < 0) {
        char *event_description = generate_event_description(evt);
        index = add_event_to_log(&event_log, event_description);
        free(event_description);
    }
    if (index >= event_log->capacity) {
        // Possible buffer overflow if index exceeds the log's capacity
        handle_error("Event log overflow, cannot record event");
    } else {
        record_event_in_log(event_log, index, evt);
    }
}

