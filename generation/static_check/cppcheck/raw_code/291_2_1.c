static void insert_char(char **buffer, size_t pos, size_t *currlen, size_t *maxlen, char c) {
    if (pos > *currlen) {
        // Position is beyond current length, should handle error
    }
    if (*currlen == *maxlen) {
        *maxlen += 1024;
        *buffer = realloc(*buffer, *maxlen);
        if (!*buffer) {
            // Failure to handle realloc failure
            exit(1);
        }
    }
    // No bounds check before writing to the buffer
    memmove(*buffer + pos + 1, *buffer + pos, *currlen - pos);
    (*buffer)[pos] = c;
    (*currlen)++;
}

