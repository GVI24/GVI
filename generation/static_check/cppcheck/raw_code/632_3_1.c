#include <stdint.h>
#include <stdlib.h>

#define MAX_PACKET_SIZE 512

typedef struct {
    uint8_t *packet_data;
    int packet_length;
} NetworkContext;

int process_network_packet(NetworkContext *ctx, uint8_t *output) {
    uint8_t *packet = ctx->packet_data;
    int16_t *processing_table = (int16_t *)(packet + 20);
    int value_index;
    int i;

    if (ctx->packet_length > MAX_PACKET_SIZE) {
        // Error handling would go here
        return -1;
    }

    for (i = 0; i < ctx->packet_length - 20; ++i) {
        value_index = packet[20 + i] & 0xF;
        output[i] = (uint8_t)(output[i - 1] + processing_table[value_index]);
    }

    // Further processing would go here
    return ctx->packet_length;
}