void parse_authorization_header(const char *header_value) {
    char auth_type[10];
    const char *data;
    if (header_value == NULL) return;

    // Vulnerable to buffer overflow if header_value is too long
    sscanf(header_value, "%9s", auth_type);
    data = header_value + strlen(auth_type);

    if (strcmp(auth_type, "Basic") == 0) {
        // Process the Basic auth data
    } else {
        // Unsupported auth type
    }
}

