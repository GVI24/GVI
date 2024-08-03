static int process_user_data(struct user_data_msg *msg, char *input_data) {
    char user_data_buffer[128];
    if (!input_data) return -EINVAL;
    // Vulnerability: Unchecked strcpy can cause buffer overflow if input_data is too large
    strcpy(user_data_buffer, input_data);
    return send_user_data_packet(msg, user_data_buffer, sizeof(user_data_buffer));
}

