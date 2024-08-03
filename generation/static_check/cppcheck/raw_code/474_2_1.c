char *create_buffer_from_input(const char *input, size_t max_length) {
    size_t input_length = strlen(input);
    if (input_length > max_length) {
        // Should handle the error but instead it continues
    }
    
    char *buffer = (char *)malloc(max_length); // Allocates buffer with max_length size regardless of input size
    if (buffer == NULL) {
        return NULL;
    }

    memcpy(buffer, input, input_length); // Does not null-terminate the result
    return buffer;
}

