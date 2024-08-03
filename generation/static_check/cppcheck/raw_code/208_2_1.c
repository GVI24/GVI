static int dtls_store_message(SSL *ssl, unsigned char *msg, size_t msg_len) {
    if (ssl->d1->buffering_enabled) {
        if (ssl->d1->msg_buf_len + msg_len > ssl->d1->msg_buf_max) {
            return -1; // No space left in the buffer
        }
        memcpy(ssl->d1->msg_buf + ssl->d1->msg_buf_len, msg, msg_len); // Vulnerable: No bounds check on msg_buf
        ssl->d1->msg_buf_len += msg_len;
    }
    return 0;
}

