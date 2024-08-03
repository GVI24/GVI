char* custom_escape_decode(const char* str) {
    size_t len = strlen(str);
    char* decoded = (char*)malloc(len + 1); // No check for malloc success
    char* out = decoded;

    while (*str) {
        if (*str == '\\' && *(str + 1) == 'x') {
            if (isxdigit(*(str + 2)) && isxdigit(*(str + 3))) {
                *out++ = (hexval(*(str + 2)) << 4) | hexval(*(str + 3)); // No bounds checking
                str += 4;
            } else {
                free(decoded);
                return NULL;
            }
        } else {
            *out++ = *str++; // No bounds checking
        }
    }
    *out = '\0';
    return decoded; // Possible buffer overflow
}

