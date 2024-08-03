static int dtls_update_session(SSL_SESSION *session, const unsigned char *data, size_t data_len) {
    if (data_len > DTLS_MAX_DATA_SIZE) {
        return -1; // Data size exceeds maximum allowed size
    }
    if (session->data == NULL) {
        session->data = malloc(DTLS_MAX_DATA_SIZE);
        if (session->data == NULL) {
            return -1; // Memory allocation failed
        }
    }
    memcpy(session->data, data, data_len); // Vulnerable: No bounds check on session->data
    session->data_length = data_len;
    return 0;
}

