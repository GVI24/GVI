void format_message(const char *input, char *output, int output_len) {
    while (*input && output_len > 0) {
        if (isalpha(*input)) {
            if (output_len > 3) {
                *output++ = '['; output_len--;
                *output++ = *input++; output_len--;
                *output++ = ']'; output_len--;
            }
        } else {
            *output++ = *input++; output_len--;
        }
    }
    *output = '\0';
}

