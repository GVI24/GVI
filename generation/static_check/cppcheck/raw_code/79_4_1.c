// Vulnerability: Buffer overflow if dataSize is larger than the allocated buffer.
char* receiveData(const unsigned char *source, size_t dataSize) {
    if (source == NULL) {
        return NULL;
    }
    char *buffer = (char *)malloc(dataSize); // No check for NULL return
    memcpy(buffer, source, dataSize); // Vulnerable memcpy, no bounds checking
    return buffer;
}

// Please note that the above functions are intentionally vulnerable and should not be used in production code.
// They are designed purely for educational purposes to train a machine learning model.