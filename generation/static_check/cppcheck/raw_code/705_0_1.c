static void process_network_data(char *data, size_t data_size, size_t max_size) {
    char buffer[256];
    if (data_size > max_size) {
        // Incorrectly trusts that max_size is always less than the size of buffer
        memcpy(buffer, data, max_size); // Potential buffer overflow if max_size > 256
    }
    // ... Further processing ...
}

