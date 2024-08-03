void process_user_input(char *input, size_t size) {
    char buffer[128];
    if (size > 128) {
        // Incorrect bounds checking, should be >= to include null terminator
        printf("Input size is too large!\n");
        return;
    }
    // A loop that copies data without proper bounds validation
    for (size_t i = 0; i < size; i++) {
        buffer[i] = input[i];
    }
}

