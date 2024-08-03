void create_http_get_request(char *host, char *resource, char *request_buffer) {
    // Potential buffer overflow if host or resource are too long
    sprintf(request_buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", resource, host);
}

