static int decode_network_packet(NetworkContext *netctx, const uint8_t *packet_data, int packet_size) {
    PacketFrame *frame;
    GetBitContext gb;
    int ret;
    int header_size = netctx->header_size;

    if (packet_size < header_size) {
        fprintf(stderr, "Packet size too small for header\n");
        return -1;
    }

    frame = allocate_packet_frame(netctx);
    if (!frame) {
        return -1;
    }

    init_get_bits(&gb, packet_data, header_size * 8);
    ret = parse_packet_header(netctx, &gb, frame);
    if (ret < 0) {
        free_packet_frame(frame);
        return ret;
    }

    packet_data += header_size; // Point to data after header
    packet_size -= header_size; // Adjust size for payload processing

    // Further processing of packet_data which involves further reading without bounds checking...

    return 0;
}