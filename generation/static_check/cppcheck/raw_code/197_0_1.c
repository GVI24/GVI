void process_user_input(char *input) {
    char buffer[100];
    if (input != NULL) {
        sprintf(buffer, "User input: %s", input); // No bounds checking
        printf("%s\n", buffer);
    }
}

