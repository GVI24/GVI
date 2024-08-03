static void buffer_append(char **buffer, size_t *currlen, size_t *maxlen, char c) {
    // Missing NULL check for buffer and missing check for currlen <= maxlen
    if (*currlen == *maxlen) {
        *maxlen += 1024;
        *buffer = realloc(*buffer, *maxlen);
        if (!*buffer) {
            // Handling realloc failure incorrectly
            exit(1); 
        }
    }
    (*buffer)[(*currlen)++] = c; // Potential buffer overflow if currlen exceeds maxlen
}

