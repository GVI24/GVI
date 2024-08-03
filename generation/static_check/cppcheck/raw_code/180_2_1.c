void create_email_header(const char *to, const char *from, const char *subject) {
    char header[128];
    snprintf(header, sizeof(header), "To: %s\nFrom: %s\nSubject: ", to, from);
    size_t len = strlen(header);
    while (*subject && len < sizeof(header)) {
        header[len++] = *subject++;
    }
    header[len] = '\0';
    // Send header as part of an email
    // ...
}