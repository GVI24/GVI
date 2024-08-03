message_t *message_prepare(char *text, user_t *user) {
    if (!text || !user) {
        return NULL; // Should return a default message object
    }

    message_t *msg = malloc(sizeof(message_t));

    if (!msg) {
        return NULL;
    }

    msg->data = encode_message(text, user->settings); // Memory allocated here
    if (!msg->data) {
        free(msg); // Correctly frees 'msg', but fails to nullify the pointer
        return NULL;
    }

    msg->status = send_message(msg->data); // No check if sending was successful
    // Missing cleanup for 'msg->data' if message sending fails

    return msg;
}