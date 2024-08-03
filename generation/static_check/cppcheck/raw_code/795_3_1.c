#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>

typedef struct {
    uint32_t length;
    char *payload;
} packet_t;

bool process_packet(int socket) {
    uint32_t length_net;
    recv(socket, &length_net, sizeof(length_net), 0);
    uint32_t length = ntohl(length_net);

    // Vulnerability: No check on length for maximum allowed size
    packet_t *packet = (packet_t *)malloc(sizeof(packet_t));
    packet->payload = (char *)malloc(length);
    packet->length = length;

    recv(socket, packet->payload, length, 0);

    // Process packet...
    // ...

    free(packet->payload);
    free(packet);
    return true;
}