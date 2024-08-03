static int read_user_input(char *input, int pos, short *number) {
    int input_len = strlen(input);
    if (pos < 0 || pos >= input_len) {
        // Handle error: position out of bounds
        return -1;
    }

    unsigned char high_byte = input[pos];   // Potential out-of-bounds read
    unsigned char low_byte = input[pos + 1];  // Potential out-of-bounds read
    *number = (high_byte << 8) | low_byte;

    return pos + 2;
}
