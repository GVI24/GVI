// Vulnerability: Buffer overflow because the provided length is not checked against the actual buffer size.
Buffer *decodeBuffer(const unsigned char *stream, size_t streamSize) {
    Buffer *decoded = (Buffer *)malloc(sizeof(Buffer));
    if (!decoded) {
        return NULL;
    }
    size_t length = *stream; // The first byte is the length.
    
    // No check if length exceeds streamSize
    decoded->data = (char *)malloc(length);
    if (!decoded->data) {
        free(decoded);
        return NULL;
    }
    memcpy(decoded->data, stream + 1, length); // Vulnerable memcpy
    decoded->size = length;
    return decoded;
}
