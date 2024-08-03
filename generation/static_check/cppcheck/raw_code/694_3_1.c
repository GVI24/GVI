void construct_message(const char* header, const char* body, char* message, size_t message_size) {
    size_t header_len = strlen(header);
    size_t body_len = strlen(body);
    if (header_len + body_len + 2 > message_size) { // Missing '=' leads to off-by-one
        // No error signaled, just returns
        return;
    }
    sprintf(message, "%s\n%s", header, body); // Unsafe use of sprintf, no bounds checking
}

