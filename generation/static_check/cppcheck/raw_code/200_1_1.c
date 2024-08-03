void log_client_activity(struct evhttp_request* req, const char* log_entry) {
    struct evbuffer* log_buffer = evbuffer_new();
    if (!log_buffer) return;

    // Potential uncontrolled format string vulnerability
    evbuffer_add_printf(log_buffer, log_entry);
    
    // Simulating a function that writes the log to a file or sends over the network
    write_log_to_file(log_buffer);
    evbuffer_free(log_buffer);
}

