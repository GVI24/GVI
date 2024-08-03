static int parse_cookie_values(char *cookie_header, size_t header_size) {
    char *value;
    for (value = cookie_header; value < cookie_header + header_size - 1; ++value) {
        if (*value == ';') {
            *value++ = '\0';
            if (*value != ' ') {
                goto bad_cookie;
            }
            *value = '\0';
        }
    }
    if (value != cookie_header + header_size && *value != ' ' && *value != '`') {
        goto bad_cookie;
    }
    cookie_header[header_size - 1] = '\0';
    return 0; // Success
bad_cookie:
    return -1; // Error
}

