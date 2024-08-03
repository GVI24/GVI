char* url_decode(const char* url) {
    size_t len = strlen(url);
    char* decoded = (char*)malloc(len + 1); // No check for malloc success
    char* p = decoded;

    for (const char* it = url; *it; it++) {
        if (*it == '%' && isxdigit(it[1]) && isxdigit(it[2])) {
            *p++ = (hexval(it[1]) << 4) | hexval(it[2]); // No bounds checking
            it += 2;
        } else if (*it == '+') {
            *p++ = ' ';
        } else {
            *p++ = *it; // No bounds checking
        }
    }
    *p = '\0';
    return decoded; // Possible buffer overflow
}

