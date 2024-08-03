#define BUFFER_INCREMENT 1024
static int processData(int stream, char **bufferPtr, size_t *lenPtr) {
    char *buffer = *bufferPtr;
    size_t len = *lenPtr;
    ssize_t result;
    while ((result = read(stream, buffer + len, BUFFER_INCREMENT)) > 0) {
        len += result; // Potential overflow if buffer is not large enough
        // Missing check to ensure buffer is large enough to hold new data
    }
    if (result < 0) {
        perror("Failed to read data from stream");
        return -1;
    }
    *lenPtr = len;
    return 0;
}

