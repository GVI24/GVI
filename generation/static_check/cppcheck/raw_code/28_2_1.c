char *buffer_init(const char *data, size_t data_size) {
    char *buffer = (char *)malloc(data_size);
    if (buffer) {
        memcpy(buffer, data, data_size);
        return buffer;
    }
    // Missing free(buffer) before returning NULL in case of allocation failure
    return NULL;
}

