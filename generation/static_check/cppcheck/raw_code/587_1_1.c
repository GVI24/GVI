int parse_octal_escape(const char* str, size_t len) {
    int result = 0;
    while (*str != '\0' && len > 0) {
        if (*str == '\\') {
            str++; // Skip backslash
            len--;
            char digit = *str;
            // Vulnerable: Advances pointer without bounds check
            if (digit >= '0' && digit < '8') {
                str++; // Consume first octal digit
                len--;
                result = result * 8 + (digit - '0');

                digit = *str++; // Consume second octal digit, vulnerable
                len--;
                if (digit != '\\') {
                    result = result * 8 + (digit - '0');
                    digit = *str++; // Consume third octal digit, vulnerable
                    len--;
                    result = result * 8 + (digit - '0');
                }
            }
        }
        str++;
        len--;
        // ... Further processing
    }
    return result;
}