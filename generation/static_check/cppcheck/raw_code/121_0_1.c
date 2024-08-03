// Vulnerable Function Example 1
char * string_duplicate(const char *s, size_t n) {
    if (s == NULL || n == 0) {
        return NULL;
    }
    char *dup = malloc(n);
    if (dup == NULL) {
        return NULL;
    }
    memcpy(dup, s, n); // Potential buffer overflow if n is larger than the actual length of s
    return dup;
}