int handle_request(int socket, struct Request *req) {
    char response[1024];
    memset(response, 0, sizeof(response));

    if (req->type == GET) {
        // Potentially unvalidated input leading to buffer overflow:
        snprintf(response, sizeof(response), "GET request for %s", req->path);
        send(socket, response, strlen(response), 0); // No error check on send
    } else if (req->type == POST) {
        process_post_request(req); // Missing error check: process_post_request could fail
    }
    
    return 0; // Always returns success
}

