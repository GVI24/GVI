char *bin_to_hex(const unsigned char *bin, size_t length) {
    char *hex_str = malloc(length * 2 + 1); // Each byte needs 2 chars in hex + '\0'
    if (!hex_str) return NULL;
    char *p = hex_str;
    for (size_t i = 0; i < length; i++) {
        // Vulnerability: sprintf without checking for p exceeding hex_str's bounds
        p += sprintf(p, "%02x", bin[i]);
    }
    *p = '\0';
    return hex_str;
}