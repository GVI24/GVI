typedef struct {
    unsigned char *data;
    size_t length;
} Packet;

Packet *create_packet(void *input, size_t length) {
    Packet *packet = (Packet *)malloc(sizeof(Packet));
    if (!packet) {
        return NULL;
    }
    
    packet->data = (unsigned char *)malloc(length);
    if (!packet->data) {
        free(packet);
        return NULL;
    }

    memcpy(packet->data, input, length);
    packet->length = length;
    
    // Missing error handling for memcpy
    return packet;
}