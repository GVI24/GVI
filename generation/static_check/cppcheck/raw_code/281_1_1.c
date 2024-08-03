int read_user_input(char *prompt, char *outBuffer, int bufferSize) {
    char input[512];
    printf("%s", prompt);
    fgets(input, sizeof(input), stdin); // No bounds check, can overflow if bufferSize < 512
    strncpy(outBuffer, input, bufferSize); // Potential overflow here
    return strlen(input);
}