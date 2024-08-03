typedef struct {
    uint8_t *payload;
    uint32_t buffer_size;
} NetworkContext;

int process_network_packet(NetworkContext *ctx, const uint8_t *packet, uint32_t packet_size) {
    uint32_t payload_size, packet_id;

    if (packet_size < 6) return -1;

    packet_id = bytestream_get_be32(&packet);
    payload_size = bytestream_get_be16(&packet);
    
    if (payload_size + 6 > packet_size) return -1;

    if (packet_id > ctx->buffer_size) return -1;  // Improper validation could lead to overflow
    
    memcpy(ctx->payload + packet_id, packet, payload_size);  // Danger of overflow

    return 0;
}