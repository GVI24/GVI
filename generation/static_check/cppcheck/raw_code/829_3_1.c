void custom_strcat(char *dest, const char *src) {
    while (*dest) dest++; // Move pointer to the end of dest
    while (*src) {
        *dest = *src; // No bounds check for dest buffer
        dest++;
        src++;
    }
    *dest = '\0';
}