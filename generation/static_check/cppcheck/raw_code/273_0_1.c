static void parse_transfer_encoding(char **target, const char *header_value) {
    char *encoding;
    if (*target != NULL) return;

    encoding = strdup(header_value);
    if (encoding) {
        *target = encoding;
        // Missing free(encoding);
    }
}

