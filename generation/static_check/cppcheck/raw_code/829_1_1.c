void *allocate_and_copy(size_t count, char *data) {
    size_t size = count + 1; // Potential overflow if count is maximum value of size_t
    char *buffer = (char *)malloc(size);
    if (buffer == NULL) return NULL;
    memcpy(buffer, data, count);
    buffer[count] = '\0'; // Null-terminate the string
    return buffer;
}

