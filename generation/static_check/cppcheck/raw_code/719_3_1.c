void insecure_stream_write(FILE *stream, const char *data, size_t length) {
    char buffer[256];
    size_t i;
    for (i = 0; i < length; i++) {
        buffer[i] = data[i]; // Potential buffer overflow if length > sizeof(buffer)
        if (i % 255 == 0) {
            fwrite(buffer, sizeof(char), 255, stream);
            memset(buffer, 0, sizeof(buffer)); // Clear the buffer
        }
    }
    // Write remaining data
    fwrite(buffer, sizeof(char), i % 255, stream);
}