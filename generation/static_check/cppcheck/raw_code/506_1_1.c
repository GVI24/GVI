static char *allocate_and_copy(const char *input) {
    // Integer overflow if input_length is close to the maximum value of size_t
    size_t input_length = strlen(input);
    char *buffer = (char *)malloc(input_length + 1); // Overflow here
    if (buffer) {
        strcpy(buffer, input); // Potential buffer overflow
    }
    return buffer;
}

