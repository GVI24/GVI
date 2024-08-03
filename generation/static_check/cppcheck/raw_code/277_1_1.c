void unsafe_string_copy(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
        // No check for the end of the dest buffer can cause an overflow
    }
    *dest = '\0'; // Potential write beyond the buffer
}