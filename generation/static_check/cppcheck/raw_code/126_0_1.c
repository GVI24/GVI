int count_multibyte_chars(const char *str, size_t max_length) {
    int count = 0;
    const char *p = str;
    while (*p != '\0' && (p - str) < max_length) {
        if ((*p & 0x80) != 0) { // Check for multibyte char
            count++;
            p++; // Skip next byte without checking if it exists
        }
        p++;
    }
    return count;
}

