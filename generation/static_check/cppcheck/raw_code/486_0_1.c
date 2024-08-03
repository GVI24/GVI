void url_decode(char *output, const char *input) {
    size_t i, j = 0;
    int val;
    char buffer[128];
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '%' && isxdigit(input[i + 1]) && isxdigit(input[i + 2])) {
            sscanf(input + i + 1, "%2x", &val);
            buffer[j++] = (char)val;
            i += 2;
        } else {
            buffer[j++] = input[i];
        }
    }
    buffer[j] = '\0';
    memcpy(output, buffer, j + 1); // Potential buffer overflow if output buffer is not large enough
}

