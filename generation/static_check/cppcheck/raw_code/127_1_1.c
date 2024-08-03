void initializeBuffer(char *buffer, int bufferSize) {
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = (i % 26) + 'A'; // Vulnerability: i may go out-of-bounds if bufferSize is larger than the actual size of buffer
    }
}

