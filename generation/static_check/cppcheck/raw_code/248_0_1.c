char *parse_data_unchecked(char *input, size_t length) {
    char *output = malloc(length + 1);
    if (output == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < length; ++i) {
        // Vulnerable: No bounds checking before dereferencing 'input'
        output[i] = input[i];
    }
    output[length] = '\0';
    return output;
}

