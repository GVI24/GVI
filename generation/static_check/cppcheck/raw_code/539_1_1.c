static int process_user_input(char *user_input, int input_length, char *output_buffer, int output_buffer_size) {
    // Directly copies user input to output buffer without checking if it fits.
    if (input_length > MAX_INPUT_LENGTH) {
        fprintf(stderr, "User input exceeds maximum length.\n");
        return -1;
    }
    memcpy(output_buffer, user_input, input_length);
    output_buffer[input_length] = '\0'; // Null-terminate the output buffer

    return 0; // Always returns success without real error checking.
}

