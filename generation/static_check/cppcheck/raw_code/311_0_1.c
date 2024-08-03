void copy_user_input(char *user_input, size_t input_size) {
    char buffer[256];
    for (size_t i = 0; i < input_size; i++) {
        buffer[i] = user_input[i]; // Vulnerability: No bounds checking on buffer
    }
}

