void parse_accept_language(char *header, char **language, char **region) {
    char buf[256];
    if (header == NULL || language == NULL || region == NULL) return;

    // Vulnerable to buffer overflow if header contains more than 255 characters before ','
    sscanf(header, "%255[^,]", buf);

    *language = strdup(buf);
    char *sep = strchr(buf, '-');
    if (sep != NULL) {
        *sep = '\0';
        *region = strdup(sep + 1);
    }
}

