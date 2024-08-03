static void free_packet(NetworkContext *net, Packet *pkt) {
    if (pkt->payload && pkt->status != PACKET_STATUS_SHARED) {
        free_packet_payload(net, pkt);
    }
    
    av_freep(&pkt->header);
    av_freep(&pkt->checksum_data);
    // Missing setting of pkt->checksum_data to NULL after free

    if (pkt->status == PACKET_STATUS_SHARED) {
        pkt->raw_packet = NULL;
        pkt->status = 0;
    }
}

