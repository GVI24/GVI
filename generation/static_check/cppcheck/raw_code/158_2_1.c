void log_request(struct evhttp_request *req) {
    char log_entry[128];

    // Vulnerable: user-controlled req->uri in log message without bounds checking
    snprintf(log_entry, sizeof(log_entry), "Request URI: %s", req->uri);
    puts(log_entry);
}
