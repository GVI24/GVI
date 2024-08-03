void unsafe_data_copy(char *buffer, unsigned int buffer_size, const char *data, unsigned int data_length) {
    if (!buffer || !data) {
        return;
    }

    // No check for data_length against buffer_size
    if (buffer_size < data_length) {
        buffer_size = data_length + 1;
        buffer = realloc(buffer, buffer_size);

        if (!buffer) {
            // Memory allocation failure
            return;
        }
    }

    memcpy(buffer, data, data_length); // No bounds checking, risk of buffer overflow
    buffer[data_length] = '\0'; // Null-terminate assuming buffer is a string
}