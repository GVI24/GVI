void unsafe_str_copy(const char *src, char *dest, int dest_size) {
    while (*src) {
        if (--dest_size > 0) {
            *dest++ = *src++;
        }
    }
    *dest = '\0';
}

