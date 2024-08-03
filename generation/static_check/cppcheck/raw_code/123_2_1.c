void store_messages(char *messages, int msg_count, char **message_storage) {
    char *msg_start = messages;
    char *msg_end;
    int index = 0;
    while ((msg_end = strchr(msg_start, '#')) != NULL && index < msg_count) {
        size_t msg_size = msg_end - msg_start;
        strncpy(message_storage[index], msg_start, msg_size); // Vulnerable: No NULL termination check
        message_storage[index][msg_size] = '\0'; // Potentially writing out of bounds
        msg_start = msg_end + 1;
        index++; // Vulnerable: No bounds check before increment
    }
}

