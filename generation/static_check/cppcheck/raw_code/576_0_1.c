static int process_private_message(struct Client *client_p, char *message) {
    if (message == NULL || client_p == NULL) return 0;

    char buffer[512];
    if (strlen(message) > 511) {
        // Message too long, but not safely handled
        return -1;
    }
    strcpy(buffer, message); // Potential buffer overflow if message is not null-terminated

    // Process the message and take some action
    // ...
    return 1;
}

