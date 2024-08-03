// Potential Vulnerability: Buffer Overflow
void process_user_input(char *input, int size) {
    char buffer[256];
    if (input == NULL) {
        // Handle NULL pointer...
        return;
    }
    // If size is larger than the buffer, this will lead to a buffer overflow.
    for (int i = 0; i < size; i++) {
        buffer[i] = input[i];
    }
    // Process buffer...
}
