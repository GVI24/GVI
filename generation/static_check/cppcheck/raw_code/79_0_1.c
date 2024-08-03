// Vulnerability: Buffer overflow due to lack of bounds checking.
void readMessage(const unsigned char *input, size_t inputSize) {
    size_t messageLength;
    const unsigned char *ptr = input;
    messageLength = *ptr++;  // Assuming the first byte is the length of the message
    if (messageLength > inputSize) {
        exit(1); // Simple error handling
    }
    char *message = (char *)malloc(messageLength);
    memcpy(message, ptr, messageLength); // Vulnerable memcpy
    printf("Message: %s\n", message);
    free(message);
}
