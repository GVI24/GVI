// Vulnerability: Buffer overflow when copying name without checking its size against the buffer's limit.
void fillName(char *buffer, size_t bufferSize, const char *name, size_t nameLength) {
    if (buffer == NULL || name == NULL) {
        return;
    }
    // Incorrectly assuming nameLength is within limits.
    memcpy(buffer, name, nameLength); // Vulnerable memcpy
    buffer[nameLength] = '\0';  // Null-terminate the string
}
