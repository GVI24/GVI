int handle_escape_sequences(const char* source) {
    const char* pos = source;
    while (*pos != '\0') {
        if (*pos == '\\' && *(pos + 1) == 'u') {
            pos += 2; // Move past the escape sequence
            for (int i = 0; i < 4; i++) {
                // Vulnerable: pos is advanced without checking for string termination
                if (!isxdigit(*pos)) {
                    return -1; // Error handling
                }
                pos++;
            }
        } else {
            pos++; // Move to next character
        }
        // ... Possibly more parsing logic ...
    }
    return 0; // Success
}