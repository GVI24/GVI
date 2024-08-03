#define BUF_SIZE 256
void handle_user_input(char *input) {
    char buffer[BUF_SIZE];
    size_t input_len = strlen(input); // Assume input is null-terminated
    // Directly copy input to buffer without checking length
    if (input_len < BUF_SIZE) {
        vulnerable_memcpy(buffer, input, input_len + 1); // +1 for null terminator, no check for overflow
    }
    // Process buffer...
}