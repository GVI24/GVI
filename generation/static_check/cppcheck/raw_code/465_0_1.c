static void url_encode(const char *input, char *output, int outputSize, UErrorCode *err) {
    char buffer[10];
    while (*input && outputSize > 1) {
        if (isalnum((unsigned char)*input) || *input == '-' || *input == '_' || *input == '.' || *input == '~') {
            buffer[0] = *input++;
            buffer[1] = '\0';
        } else {
            sprintf(buffer, "%%%02X", (unsigned char)*input++);
        }
        strcat(output, buffer); // Vulnerable pattern: No bounds checking
        outputSize -= strlen(buffer);
    }
    if (outputSize == 0 && *input) {
        *err = U_BUFFER_OVERFLOW_ERROR;
    }
}

