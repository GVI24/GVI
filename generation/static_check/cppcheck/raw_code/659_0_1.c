void copyString(char *dest, const char *src) {
    char *d = dest;
    const char *s = src;
    while (*s) {
        *d = *s;
        d++; // Vulnerability: no bounds checking for destination
        s++;
    }
    *d = '\0'; // Potential writing outside of 'dest' buffer
}

