void log_network_event(struct net_event *event, struct log_buffer *logbuf) {
    struct event_log_entry entry;
    entry.timestamp = time(NULL);
    strlcpy(entry.event_message, event->message, sizeof(entry.event_message));

    // Potential vulnerability if log_event uses a direct copy without bounds checking
    log_event(logbuf, &entry, sizeof(entry));
}

