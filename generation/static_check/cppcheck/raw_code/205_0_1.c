void unsafe_string_copy(char *dest, const char *src, size_t dest_size) {
    while (*src) {
        if (dest_size == 0) {
            // Missing check to prevent buffer overflow
            break;
        }
        *dest++ = *src++;
        dest_size--;
    }
    *dest = '\0'; // Null-terminate
}

