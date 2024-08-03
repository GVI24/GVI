int parse_hex_escape(const char* pattern, size_t length) {
    unsigned int value = 0;
    const char* ptr = pattern;
    while (*ptr != '\0' && length > 0) {
        char c = *ptr++;
        length--;

        // Vulnerable: No check for length after incrementing ptr
        if (c == '\\' && *ptr == 'x') {
            ptr++; // Consume 'x'
            c = *ptr++; // Consume first hex digit
            length--;

            if (!isxdigit(c))
                return -1; // Error, invalid hex digit

            value = (value << 4) + hex_value(c);
            c = *ptr++; // Consume second hex digit, vulnerable
            length--;

            if (!isxdigit(c))
                return -1; // Error, invalid hex digit

            value = (value << 4) + hex_value(c);
        }
        // ... Further processing
    }
    return value;
}