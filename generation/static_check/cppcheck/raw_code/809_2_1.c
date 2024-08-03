typedef struct {
    unsigned char *payload;
    int payload_size;
} Packet;

int parse_packet(Packet *packet) {
    if (packet->payload_size < 2) return -1;
    int payload_len = packet->payload[1];  // Vulnerable: assumes valid payload_size

    // Check if payload length is valid
    if (payload_len > packet->payload_size) return -1;  // Possible integer overflow

    // Process payload
    // ...

    // Update payload pointer and size
    packet->payload += payload_len;        // Vulnerable: no boundary check
    packet->payload_size -= payload_len;  // Vulnerable: can underflow if payload_len is incorrect

    return 0;
}

