void process_user_data(const char *data, size_t data_length) {
    // Vulnerability: The length check could overflow if 'data_length' is too large
    if (data_length + 1 > data_length) {
        char *buffer = malloc(data_length + 1);
        memcpy(buffer, data, data_length);
        buffer[data_length] = '\0';
        // ... processing logic...
        free(buffer);
    }
}