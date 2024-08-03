static int formatLogMessage(char *userInput) {
    char logBuffer[100];
    if (sprintf(logBuffer, "User input: %s", userInput) > sizeof(logBuffer)) { // Vulnerable: No bounds check
        handle_error();
        return -1;
    }
    printf("%s\n", logBuffer); // Potential buffer overflow
    return 0;
}

