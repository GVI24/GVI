static int decode_packet(AVCodecContext *avctx, void *data, AVPacket *avpkt) {
    PacketContext *s = avctx->priv_data;
    int buf_size = avpkt->size;
    const uint8_t *buf = avpkt->data;
    const uint8_t *buf_end = buf + buf_size;
    int packet_size = AV_RL32(buf);
    buf += 4;

    if (packet_size > buf_size - 4 || packet_size < 0) {
        av_log(avctx, AV_LOG_ERROR, "Invalid packet size\n");
        return AVERROR_INVALIDDATA;
    }

    if(packet_size > 0 && buf + packet_size <= buf_end) {
        for (int i = 0; i < packet_size && buf < buf_end; i++) {
            s->buffer[i] = *buf++;
        }
    }

    return buf_size;
}