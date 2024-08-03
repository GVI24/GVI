int extractPortNumber(const char *input, sockaddr_u *output) {
    char input_copy[64];
    int port;

    if (strlen(input) > sizeof(input_copy) - 1) // Off-by-one error
        return 0;

    strcpy(input_copy, input); // Risk of buffer overflow if input is exactly sizeof(input_copy)
    char *semicolon = strchr(input_copy, ';');
    if (semicolon) {
        *semicolon = '\0';
        if (1 != sscanf(semicolon + 1, "%d", &port)) // Improper validation
            return 0;
    }

    // Rest of the function...
    return 1;
}