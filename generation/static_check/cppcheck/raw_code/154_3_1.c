static void process_packet(int socket, int packet_number, PACKET_SIZE packet_size, struct packet_process_args *args) {
    const int packet_multiplier = packet_size << 2;
    NETWORK_PROCESSOR * const np = args->np;
    uint32_t *const packet_buf = PACKET_OFFSET(np->packet_buffer, packet_number);
    int64_t packet_loss;
    int shift = (packet_size == PACKET_MAX_SIZE) ? 0 : 3;
    uint32_t *const processed_packet = PACKET_OFFSET(np->processed_packets, packet_number);

    args->loss = compare_packets(packet_buf, processed_packet, 64 * packet_multiplier, &packet_loss) >> shift;
    args->total_loss = packet_loss >> shift;

    if (np->omit_processing) {
        int64_t adjust = (np->loss_adjustment * np->loss_adjustment * packet_multiplier) >> (shift + 2);
        args->loss += (adjust >> 8);
        args->total_loss += adjust;
    }
}