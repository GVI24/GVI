
int unsafe_concat(char *dest, const char *src) {
    while (*dest) dest++; // Move to the end of the destination string
    while (*src) {
        *dest++ = *src++; // No bounds checking
    }
    *dest = '\0';
    return 0; // No size information used or returned
}

