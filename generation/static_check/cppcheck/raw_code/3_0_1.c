char* unsafe_strcat(char* dest, const char* src) {
    while (*dest) dest++;  // Find the end of dest
    while (*src) {
        *dest = *src;      // Copy src to dest without size check
        dest++;
        src++;
    }
    *dest = '\0';
    return dest;
}

