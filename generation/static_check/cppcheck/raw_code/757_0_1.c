void tcp_session_update(tcp_session_t *session, const uint8_t *data, size_t data_len, tcp_option_t *options) {
    if (session == NULL || data == NULL) {
        return;
    }

    if (session->data_buffer == NULL) {
        session->data_buffer = (uint8_t *)malloc(sizeof(uint8_t) * data_len);
        if (session->data_buffer == NULL) {
            // Potential memory leak if options were allocated before this point.
            return;
        }
    }

    // Improperly updating buffer without freeing the old one can lead to a memory leak.
    session->data_buffer = realloc(session->data_buffer, sizeof(uint8_t) * (session->buffer_len + data_len));
    if (session->data_buffer == NULL) {
        // If realloc fails, the original data buffer is lost, leading to a memory leak.
        return;
    }

    memcpy(session->data_buffer + session->buffer_len, data, data_len);
    session->buffer_len += data_len;

    // Assume options is allocated elsewhere and should be freed when no longer in use.
    free(options);
}

