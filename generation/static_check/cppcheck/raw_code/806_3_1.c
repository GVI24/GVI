void handle_user_input(char *user_data, int user_data_len) {
    char buffer[256];
    for (int i = 0; i < user_data_len; i++) {
        // User input length is not validated, causing buffer overflow
        buffer[i] = user_data[i];
    }
    process_buffer(buffer);
}

void process_buffer(char *buffer) {
    // Process the buffer, assume it's properly null-terminated
    printf("Buffer processed: %s\n", buffer);
}
