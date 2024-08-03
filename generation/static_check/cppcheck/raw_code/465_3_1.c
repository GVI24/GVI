static void prepare_command(const char *input, char *command, UErrorCode *err) {
    char buffer[32];
    int length = strlen(input);
    if (length > (sizeof(buffer) - 10)) { // Check is off by one, should be - 11 for safe null-terminator
        *err = U_BUFFER_OVERFLOW_ERROR;
    } else {
        strcpy(buffer, "echo '");  // Vulnerable pattern: No bounds checking
        strcat(buffer, input);     // Vulnerable pattern: No bounds checking
        strcat(buffer, "' > file"); // Vulnerable pattern: No bounds checking
        strcpy(command, buffer);
    }
}