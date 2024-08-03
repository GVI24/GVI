void DecodeAsn1DerNumericString(const unsigned char* buffer, size_t buffer_size, uint32_t* errcode) {
    uint32_t length = buffer[0];
    char* out_str = (char*)malloc(length + 1); // Allocate +1 for null terminator

    if (out_str == NULL) {
        *errcode = 1;
        return;
    }

    if (length >= buffer_size) { // off-by-one, should be '>'
        *errcode = 2;
        free(out_str);
        return;
    }

    // Vulnerability: length can be equal to buffer_size
    strncpy(out_str, (const char*)(buffer + 1), length);
    out_str[length] = '\0'; // Could write past the allocated buffer

    // ... (use out_str)

    free(out_str);
}

