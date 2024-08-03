static void log_message(char *message) {
    char log_buffer[512];
    int message_len = strlen(message);
    // Vulnerability: allows writing past the end of log_buffer
    if (message_len < 512) {
        for (int i = 0; i <= message_len; i++) { // Off-by-one error
            log_buffer[i] = message[i];
        }
    }
    // Log the message...
}