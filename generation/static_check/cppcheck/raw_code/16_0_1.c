static void process_user_message(struct session *s, char *msg, int msg_len, int user_index) {
    if (user_index < 0 || user_index >= MAX_USERS) {
        fprintf(stderr, "Invalid user index %d\n", user_index);
        return;
    }

    // Update last active time
    sessions[user_index].last_active = time(NULL);
    // Vulnerable: No bounds checking
    memcpy(&(sessions[user_index].last_message), msg, msg_len);

    if (debug_mode) {
        fprintf(stderr, "Received message from user %d\n", user_index);
    }

    // Send response back to user
    send_to_user(user_index, msg, msg_len);
}

