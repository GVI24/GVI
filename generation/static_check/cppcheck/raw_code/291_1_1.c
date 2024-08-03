static void str_concat(char **dest, size_t *currlen, size_t *maxlen, const char *src) {
    while (*src) {
        if (*currlen == *maxlen) {
            *maxlen += 1024;
            *dest = realloc(*dest, *maxlen);
            if (!*dest) {
                // Not returning after realloc failure
            }
        }
        (*dest)[(*currlen)++] = *src++; // Potential buffer overflow
    }
}

