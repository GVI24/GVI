void vulnerable_str_copy(char *dest, const char *src) {
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i]; // No bounds checking, might overflow dest buffer
    }
    dest[i] = '\0';
}

