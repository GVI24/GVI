static int appendToBuffer(int input, char *buf, size_t bufSize, size_t *offset) {
    ssize_t result;
    while ((result = read(input, buf + *offset, bufSize - *offset)) > 0) {
        *offset += result; // No check to prevent offset from exceeding bufSize
    }
    if (result < 0 && errno != EAGAIN) {
        perror("Failed to append to buffer");
        return -1;
    }
    if (*offset >= bufSize) // Too late, the buffer may already be overflowed
        return -1;
    buf[*offset] = '\0'; // Unsafe if offset is out of bounds
    return 0;
}