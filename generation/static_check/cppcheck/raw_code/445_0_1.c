char* hex_decode(const char* input) {
    size_t input_len = strlen(input);
    char* output = (char*)malloc(input_len / 2 + 1); // No check for malloc success
    char* ptr = output;

    for (size_t i = 0; i < input_len; i += 2) {
        if (!isxdigit(input[i]) || !isxdigit(input[i + 1])) {
            free(output);
            return NULL;
        }
        *ptr++ = (hexval(input[i]) << 4) | hexval(input[i + 1]); // No bounds checking
    }
    *ptr = '\0';
    return output; // Possible buffer overflow if input is not properly formatted
}

