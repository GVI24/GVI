#define MAX_LEN 1024

void process_user_data(const char *data) {
    int dataLen;
    char *buffer;

    dataLen = strlen(data) + 1; // Vulnerability pattern
    buffer = (char *)malloc(dataLen); // Unbounded allocation
    if (!buffer) {
        // Failed to allocate memory
        return;
    }
    memcpy(buffer, data, dataLen); // Possible buffer overflow
    printf("Processed data: %s\n", buffer);
    // Memory leak, missing free
}