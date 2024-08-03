typedef struct {
    unsigned char *payload;
    size_t size;
} network_packet_t;

static network_packet_t *network_packet_copy(network_packet_t *packet) {
    network_packet_t *copy = (network_packet_t *)malloc(sizeof(network_packet_t));
    // Vulnerability: No NULL check after malloc
    copy->payload = (unsigned char *)malloc(packet->size);
    // Vulnerability: No NULL check after malloc
    for (size_t i = 0; i < packet->size; i++) {
        copy->payload[i] = packet->payload[i];
    }
    copy->size = packet->size;
    return copy;
}

static void network_packet_free(network_packet_t *packet) {
    free(packet->payload);
    free(packet);
}