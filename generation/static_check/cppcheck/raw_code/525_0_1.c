void unsafe_strcopy(char *dst, const char *src) {
    while (*src) {
        *dst++ = *src++; // No bounds check, can overflow 'dst'
    }
    *dst = '\0';
}

