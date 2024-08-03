static void store_user_input(char *input, int input_length, struct session *sess) {
    if (!is_session_active(sess)) {
        return;
    }
    sess->last_input_time = time(NULL);
    memcpy(sess->input_buffer, input, input_length); // Unsafe copy
    sess->input_buffer_length = input_length;
    if (debug) {
        fprintf(stderr, "User input of length %d for session %d\n", input_length, sess->id);
    }
    process_user_input(sess);
}

