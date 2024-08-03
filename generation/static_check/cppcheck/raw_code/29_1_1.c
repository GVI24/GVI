static int decode_packet(packet_t *packet, size_t size) {
    uint8_t *data;
    uint32_t value;
    int result;

    if (packet == NULL || size < 4) {
        return -1;
    }

    data = packet->data;
    for (size_t i = 0; i < size; ) {
        result = decode_uint32(data + i, &value);
        if (result != 0) {
            return -2;
        }
        i += 4; // Potential over-read if `i` is not properly checked against `size`
    }

    return 0;
}

