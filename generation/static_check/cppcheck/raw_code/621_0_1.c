void process_network_data(const char *data, size_t data_len) {
    char buffer[BUFFER_SIZE];
    if (data_len > BUFFER_SIZE) {
        // Improper boundary check can lead to buffer overflow.
        fprintf(stderr, "Data is too large!\n");
        return;
    }
    memcpy(buffer, data, data_len); // Potential buffer overflow if data_len > BUFFER_SIZE.
    // ... (rest of the processing code)
    printf("%s\n", buffer);
}

