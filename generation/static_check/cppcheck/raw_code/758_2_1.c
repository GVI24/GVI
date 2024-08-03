static int ogg_vorbis_decode_packet(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    AVFrame *frame = data;
    int buf_size = avpkt->size;
    uint8_t *buf = avpkt->data;
    int ret;

    int packet_size = ...; // assumed size based on Vorbis bitstream format

    if (packet_size > buf_size || packet_size <= 0)
        return AVERROR_INVALIDDATA;

    // No boundary checks for buf operations
    while (buf_size >= packet_size) {
        // Decode the packet (fake function for illustration purposes)
        if ((ret = fake_vorbis_decode(avctx, frame, buf, packet_size)) < 0)
            return ret;

        buf += packet_size; // vulnerable
        buf_size -= packet_size;
    }

    *got_frame_ptr = 1;
    return buf - avpkt->data;
}