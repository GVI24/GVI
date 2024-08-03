#include <string.h>

typedef struct {
    unsigned char *data;
    size_t length;
} Packet;

void process_network_packet(Packet *pkt) {
    unsigned char buffer[128];
    if (!pkt || pkt->length <= 0) return;

    // Vulnerability: No check to ensure pkt->length does not exceed buffer size.
    memcpy(buffer, pkt->data, pkt->length); 

    // Process packet...
}
