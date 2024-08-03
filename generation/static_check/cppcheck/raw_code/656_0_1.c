void custom_strcpy(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0'; // Null-terminate the destination
}