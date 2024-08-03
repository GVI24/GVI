#define MAX_PAYLOAD 256

typedef struct {
    uint8_t version;
    uint8_t flags;
    uint16_t payload_length;
    char payload[MAX_PAYLOAD];
} Message;

void handle_incoming_message(char *raw_data, size_t raw_data_length) {
    Message message;

    // Vulnerability: payload_length may be very large, overflowing the 'payload' buffer.
    message.payload_length = ntohs(*(uint16_t *)(raw_data + 2));

    // Improper length check, not accounting for the structure's other fields
    if (message.payload_length > raw_data_length) {
        // Error handling...
        return;
    }

    // Copy the payload without checking the destination buffer size
    memcpy(message.payload, raw_data + 4, message.payload_length);

    // Process message...
}