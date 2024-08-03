void *allocate_and_copy(const char *data, size_t length) {
    size_t size = length + 1; // For the null terminator
    if (size < length) { // Overflow check, but incorrect
        return NULL;
    }
    char *buffer = (char *)malloc(size);
    if (buffer != NULL) {
        memcpy(buffer, data, length);
        buffer[length] = '\0';
    }
    return buffer;
}