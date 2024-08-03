static int parse_network_header(NetworkHeader *hdr, GetBitContext *gb) {
    unsigned int bits_read = get_bits_count(gb);
    uint32_t header_data[5]; // Assume the header contains 5 uint32_t values

    // Vulnerability: No boundary check before the memcpy operation
    // Could lead to buffer overflow
    memcpy(header_data, gb->buffer + gb->index, 20);
    gb->index += 20;

    // Set header fields
    hdr->source = header_data[0];
    hdr->destination = header_data[1];
    hdr->sequence = header_data[2];
    hdr->acknowledgment = header_data[3];
    hdr->flags = header_data[4];

    // More processing
    // ...

    return get_bits_count(gb) - bits_read;
}

