void handle_client_request(char *request, int req_size, struct client *c) {
    char request_payload[512];
    if (req_size <= 0 || req_size > 1024) return;
    if (!c || !c->session_active) return;

    // Vulnerable: potential buffer overflow when copying request
    memcpy(request_payload, request, req_size);
    request_payload[req_size] = '\0'; // Potential off-by-one error
    process_client_request(c, request_payload);
}

