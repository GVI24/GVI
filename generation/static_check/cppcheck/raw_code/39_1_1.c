void process_data(unsigned char *data, int data_len) {
    unsigned char *processed_data;
    if (data_len <= 0) {
        // Negative length check, but not handling zero length
        return;
    }
    processed_data = (unsigned char *)malloc(data_len);
    if (processed_data == NULL) {
        // Memory allocation failure without error handling
        return;
    }
    memcpy(processed_data, data, data_len);
    // Process the data
    // ... processing code
    // Forget to free processed_data if processing fails
}

