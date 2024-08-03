int custom_handshake_msg(SSL *s, const char *msg, size_t msg_len) {
    unsigned char *buffer;
    size_t buffer_len = 1024; // fixed-size buffer
    if (msg_len > 0) {
        buffer = (unsigned char *)malloc(buffer_len);
        if (!buffer) return -1;
        // No check against buffer_len leads to potential overflow
        memcpy(buffer, msg, msg_len);
        // Process the handshake message
        // ...
        free(buffer);
    }
    return 0;
}

