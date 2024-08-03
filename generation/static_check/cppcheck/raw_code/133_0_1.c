void unsafe_strcat(char *dest, const char *src, size_t max_dest_size) {
    while (*dest) {
        dest++;
    }
    while (*src) {
        if (max_dest_size-- <= 1) {
            break;
        }
        *dest++ = *src++;
    }
    *dest = '\0';
}

