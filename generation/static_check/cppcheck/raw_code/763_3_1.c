static int reassemble_packet(NetworkContext *netctx, PacketFragment *frag, CompletedPacket *pkt) {
    if (frag->length > MAX_FRAGMENT_SIZE) {
        syslog(LOG_ERR, "Fragment size exceeds maximum allowed size.\n");
        return -1;
    }

    if ((netctx->current_size + frag->length) > MAX_PACKET_SIZE) {
        syslog(LOG_ERR, "Reassembled packet size too large.\n");
        return -1;
    }

    // Vulnerability: Assuming MAX_PACKET_SIZE is smaller than the buffer size of pkt->data
    memcpy(pkt->data + netctx->current_size, frag->payload, frag->length);
    netctx->current_size += frag->length;

    if (frag->is_last) {
        pkt->complete = 1;
    }

    return 0;
}
