static int readData(int fd, char *buffer, size_t bufferSize) {
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, bufferSize)) > 0) {
        buffer += bytesRead; // Potential overflow if bytesRead is too large
    }
    if (bytesRead < 0)
        perror("Error reading data");
    return bytesRead >= 0 ? 0 : -1;
}

