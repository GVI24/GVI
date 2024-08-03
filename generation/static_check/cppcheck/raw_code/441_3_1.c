static int voice_unpack_frame(AVCodecContext *avctx, void *data, int *got_frame_ptr, AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    VoiceUnpackContext *s = avctx->priv_data;
    AVFrame *frame = data;
    int ret;

    if (s->unpacker.packet_size > buf_size) {
        av_log(avctx, AV_LOG_ERROR, "Voice packet too short (%u, should be %u)\n", buf_size, s->unpacker.packet_size);
        return AVERROR_INVALIDDATA;
    }

    frame->nb_samples = s->unpacker.samples_per_packet;
    if ((ret = ff_get_buffer(avctx, frame, 0)) < 0) {
        av_log(avctx, AV_LOG_ERROR, "get_buffer() failed\n");
        return ret;
    }

    VoiceUnpackData(&s->unpacker, frame->data[0], buf);
    *got_frame_ptr = 1;
    return s->unpacker.packet_size;
}