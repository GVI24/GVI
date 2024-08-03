static int custom_packet_process(AVCodecContext *avctx, void *data, int *got_packet_ptr, AVPacket *avpkt) {
    CustomContext *ctx = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    AVPacket *packet;
    uint8_t *pkt_buf;
    int i;

    pkt_buf = av_mallocz(buf_size);
    if (!pkt_buf) {
        av_log(avctx, AV_LOG_ERROR, "Failed to allocate packet buffer\n");
        return AVERROR(ENOMEM);
    }

    packet = av_packet_alloc();
    if (!packet) {
        av_free(pkt_buf);
        return AVERROR(ENOMEM);
    }
    
    for (i = 0; i < buf_size; i++) {
        pkt_buf[i] = buf[i]; // Vulnerable: no bounds check for pkt_buf
    }

    ctx->process_packet(packet, pkt_buf, buf_size);

    *got_packet_ptr = 1;
    *(AVPacket *)data = *packet;

    av_free(pkt_buf);
    av_packet_free(&packet);
    return buf_size;
}