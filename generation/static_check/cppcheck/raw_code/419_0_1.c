char* DecodeAsn1DerIA5String(const unsigned char* buffer, uint32_t max_size, uint32_t* errcode) {
    const unsigned char* ptr = buffer;
    uint32_t length = *ptr++;  // Assuming length is directly the next byte
    char* str;

    if (length > max_size) {
        *errcode = 1;
        return NULL;
    }

    str = (char*)malloc(length + 1);
    if (!str) {
        *errcode = 2;
        return NULL;
    }

    // Vulnerability: No check on the actual buffer length
    memcpy(str, ptr, length);  
    str[length] = '\0';
    return str;
}

