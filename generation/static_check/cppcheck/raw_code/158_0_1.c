void process_request(char *user_input) {
    char buffer[1024];
    if (user_input == NULL) {
        printf("Invalid request\n");
        return;
    }

    // Vulnerable to buffer overflow if user_input is too large
    sprintf(buffer, "Received user request: %s", user_input);
    printf("%s\n", buffer);
}
