void process_data(char *buffer, size_t buffer_size, const char *input_data, size_t input_size) {
    size_t index;
    for (index = 0; index < input_size; index++) {
        if (index >= buffer_size) {
            // No protection against buffer overflow
        }
        buffer[index] = input_data[index] ^ 0xAA; // Some processing
    }
}

