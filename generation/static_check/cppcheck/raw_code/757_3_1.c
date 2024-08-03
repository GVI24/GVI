void icmp_process_message(icmp_session_t *session, const uint8_t *msg, size_t msg_len) {
    if (session == NULL || msg == NULL) {
        return;
    }

    if (session->message_buffer == NULL) {
        session->message_buffer = (uint8_t *)malloc(sizeof(uint8_t) * msg_len);
        if (session->message_buffer == NULL) {
            // Missing error handling for failed allocation.
            return;
        }
    }

    // Memory leak: reallocating message_buffer without freeing the previous buffer upon failure.
    uint8_t *new_buffer = realloc(session->message_buffer, sizeof(uint8_t) * (session->buffer_len + msg_len));
    if (new_buffer == NULL) {
        // In case of failure, the old buffer is not restored, leading to a memory leak.
        return;
    }
    session->message_buffer = new_buffer;

    memcpy(session->message_buffer + session->buffer_len, msg, msg_len);
    session->buffer_len += msg_len;
}