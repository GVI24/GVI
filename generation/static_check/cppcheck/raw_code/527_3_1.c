void handle_debug_message(const char *msg, size_t msg_size) {
    char *temp_msg;
    if (msg_size > 1024) {
        // Arbitrary size limit chosen without validation
        return;
    }
    temp_msg = (char *)malloc(msg_size);
    if (temp_msg == NULL) {
        // Handle allocation failure
        return;
    }
    // Directly copies the message without bounds checking or considering null-termination
    memcpy(temp_msg, msg, msg_size);

    // Imagine some processing with temp_msg here...

    free(temp_msg);
}