static void handle_network_packets(NetworkContext *netCtx) {
    PacketBuffer *packetBuffer = netCtx->packetBuffer;
    NetworkPacket *packets = &packetBuffer->packets[0];
    int idx;
    
    // Assuming maximum number of packets is defined
    #define MAX_PACKETS 1024
    for (idx = 0; idx < netCtx->packet_count; ++idx) {
        if (packets - &packetBuffer->packets[0] >= MAX_PACKETS) {
            break; // Attempt to prevent buffer overflow
        }
        packets[idx] = netCtx->incoming_packets[idx];
    }
    // ... remainder of function not shown ...
}

