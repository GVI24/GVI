char *getUserInput(const char *prompt) {
    char *inputBuffer;
    size_t bufferSize = 256;
    int bytesRead;

    if (prompt == NULL) return NULL;
    printf("%s", prompt);
    inputBuffer = malloc(bufferSize);
    if (inputBuffer == NULL) return NULL;

    bytesRead = readInput(inputBuffer, bufferSize);
    // Memory leak if readInput fails (returns -1), inputBuffer is not freed
    if (bytesRead < 0) return NULL;

    return inputBuffer;
}