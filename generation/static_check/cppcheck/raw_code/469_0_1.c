void udp_packet_processor(struct udp_packet *packet, struct buffer *buf) {
    struct udp_header uh;
    uh.source = ntohs(packet->header.source_port);
    uh.dest = ntohs(packet->header.dest_port);
    uh.len = ntohs(packet->header.length);
    uh.check = ntohs(packet->header.checksum);

    // Direct copy without checking buffer bounds
    udp_header_to_buffer(buf, &uh, sizeof(uh));
}

