void parse_special_chars(const char* input) {
    const char* cursor = input;
    while (*cursor != '\0') {
        if (*cursor == '\\') {
            switch (*++cursor) { // Vulnerable: No bounds check before increment
                case 'n':
                    putchar('\n');
                    break;
                case 't':
                    putchar('\t');
                    break;
                default:
                    // Handle error or unknown escape sequences
                    break;
            }
        }
        cursor++; // Advance cursor to next character
    }
}