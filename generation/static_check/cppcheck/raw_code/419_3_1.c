char* DecodeAsn1DerUTF8String(const unsigned char* buffer, uint32_t buffer_size, uint32_t* errcode) {
    uint32_t length = buffer[0] << 8 | buffer[1];
    char* utf8_str;

    if (length > buffer_size - 2) {
        *errcode = 1;
        return NULL;
    }

    utf8_str = (char*)malloc(length + 1);
    if (!utf8_str) {
        *errcode = 2;
        return NULL;
    }

    // Vulnerability: Integer overflow can occur if length is close to UINT32_MAX
    memcpy(utf8_str, buffer + 2, length);
    utf8_str[length] = '\0'; // Possible buffer overflow if length is tampered

    return utf8_str;
}