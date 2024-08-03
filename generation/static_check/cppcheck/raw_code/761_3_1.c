static int parse_network_packet(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    const uint8_t *buf_end = avpkt->data + avpkt->size;
    int header_size = 12; // Assume fixed header size
    int payload_size;
    
    if (buf_end - buf < header_size) return AVERROR_INVALIDDATA;
    payload_size = AV_RL32(buf + 8);
    buf += header_size;

    if (buf_end - buf < payload_size) return AVERROR_INVALIDDATA;

    // Process the payload
    for (int i = 0; i < payload_size; ++i) {
        if (buf_end - buf < 1) return AVERROR_INVALIDDATA;
        // Do something with payload byte
        buf++;
    }

    *got_frame = 1;
    return avpkt->size;
}