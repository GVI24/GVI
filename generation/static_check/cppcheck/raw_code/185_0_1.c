void reverse_string(char *str) {
    size_t len = strlen(str);
    char buffer[64];
    if (len < 64) {
        for (size_t i = 0; i < len; ++i) {
            buffer[len - i - 1] = str[i]; // Potential overflow if len is incorrect
        }
        buffer[len] = '\0';
        strcpy(str, buffer);
    }
}

