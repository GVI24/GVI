// Vulnerability: Potential buffer overflow as no bounds checking is done when reading 'stream'.
void processStream(const unsigned char *stream, size_t bufferSize) {
    if (stream == NULL || bufferSize == 0) {
        return;
    }
    size_t length = stream[0]; // First byte is the length
    unsigned char *data = (unsigned char *)malloc(length);
    if (data == NULL) {
        return;
    }
    memcpy(data, stream + 1, length); // Vulnerable memcpy
    // ... Process data ...
    free(data);
}
