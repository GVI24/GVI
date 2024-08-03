void parse_file_data(const char *file_data, int file_size, const int *token_positions, int num_tokens, char *parsed_data) {
    for (int i = 0; i < num_tokens; ++i) {
        int token_pos = token_positions[i]; // Potentially out-of-bounds
        if (token_pos < file_size) {
            // Directly access file_data without bounds checking
            parsed_data[token_pos] = file_data[token_pos];
        }
    }
}