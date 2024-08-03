static int decode_audio_frame_custom(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    CustomContext *cctx = avctx->priv_data;
    const uint8_t *input_buf = avpkt->data;
    int buf_size = avpkt->size;
    GetBitContext gb;

    // Vulnerability: Arithmetic operation on size may overflow
    if (buf_size * 2 < avctx->bit_rate * cctx->frame_size / avctx->sample_rate) {
        av_log(avctx, AV_LOG_ERROR, "Buffer underflow\n");
        return AVERROR(EINVAL);
    }

    AVFrame *frame = data;
    frame->nb_samples = cctx->frame_size;

    // Vulnerability: ff_get_buffer not checked against failure
    ff_get_buffer(avctx, frame, 0);

    float **out = (float **)frame->extended_data;
    init_get_bits(&gb, input_buf, buf_size << 3);

    // Vulnerability: No bounds checking for input_buf during bit reading
    for (int ch = 0; ch < avctx->channels; ++ch) {
        read_and_decompress_audio(cctx, &gb, out[ch]);
    }

    *got_frame = 1;
    return buf_size;
}

