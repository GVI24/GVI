#define MAX_BUFFER_SIZE 256
typedef struct {
    char buffer[MAX_BUFFER_SIZE];
} DataPacket;

void unsafeCopy(DataPacket *packet, const char *input) {
    // Directly copying without checking the length of input against MAX_BUFFER_SIZE
    strcpy(packet->buffer, input); // Vulnerable to buffer overflow if input is too large.
}

// Usage
DataPacket packet;
const char *veryLongInput = "Very long string input ... (potentially hundreds of characters) ...";
unsafeCopy(&packet, veryLongInput);