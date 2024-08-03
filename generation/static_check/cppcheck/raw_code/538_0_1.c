static int process_audio_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt) {
    AudioDecodeContext *ctx = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    int sample_size;

    // Vulnerability: No check for buf_size, can lead to a buffer overflow.
    sample_size = extract_sample_size(buf, buf_size);
    if (sample_size < 0) return sample_size;

    // Vulnerability: Assuming buffer has enough space for all samples without checking.
    for (int i = 0; i < sample_size; i++) {
        ctx->sample_buffer[i] = buf[i];
    }

    *got_frame = 1;
    *(AVFrame *)data = ctx->frame;
    return buf_size;
}

