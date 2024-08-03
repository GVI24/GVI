char* custom_base64_decode(const char* encoded) {
    size_t len = strlen(encoded);
    char* decoded = (char*)malloc(len); // No check for malloc success
    char* ptr = decoded;

    for (size_t i = 0; i < len; i += 4) {
        int val = custom_b64_val(encoded[i]) << 18 |
                  custom_b64_val(encoded[i + 1]) << 12 |
                  custom_b64_val(encoded[i + 2]) << 6 |
                  custom_b64_val(encoded[i + 3]); // No bounds checking

        *ptr++ = (val >> 16) & 0xFF;
        *ptr++ = (val >> 8) & 0xFF;
        *ptr++ = val & 0xFF;
    }
    *ptr = '\0';
    return decoded; // Possible buffer overflow
}