#include <stdint.h>

typedef struct {
    uint8_t *payload;
    uint32_t payload_size;
} Message;

void handle_message(Message *msg) {
    uint8_t message_buffer[512];
    if (!msg || msg->payload_size == 0) return;

    // Vulnerability: Assumes msg->payload_size is always less than message_buffer.
    for (uint32_t i = 0; i < msg->payload_size; i++) {
        message_buffer[i] = msg->payload[i];
    }

    // Do something with the message...
}
