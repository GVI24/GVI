static void escape_string(const char *src, char *dest, int max_dest_len) {
    char buffer[8];
    int i = 0;
    while (*src && i < max_dest_len - 1) {
        if (*src == '\'' || *src == '\"' || *src == '\\') {
            buffer[0] = '\\';
            buffer[1] = *src++;
            buffer[2] = '\0';
            i += 2;
        } else {
            buffer[0] = *src++;
            buffer[1] = '\0';
            i++;
        }
        strcat(dest, buffer); // Vulnerable pattern: No bounds checking
    }
    dest[i] = '\0';
}


