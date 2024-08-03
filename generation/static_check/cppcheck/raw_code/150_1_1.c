char * base64_to_ascii(const char *input, size_t length) {
    char *decoded = malloc(length); // Base64 is usually larger than decoded output
    if (!decoded) return NULL;
    // Vulnerability: Using sprintf without bounds checking
    for (size_t i = 0; i < length; i += 4) {
        sprintf(decoded + strlen(decoded), "%c", (input[i] - '0') & 0x7F); // Fake decoding logic
    }
    return decoded;
}

