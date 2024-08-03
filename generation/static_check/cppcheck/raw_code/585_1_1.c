static int decode_audio_frame(AVCodecContext *avctx, uint8_t *frame_buf, int buf_size) {
    AudioContext *ctx = avctx->priv_data;
    int hdr_size, sample_count, frame_size;
    const uint8_t *buf = frame_buf;

    // Assume buf has the following structure: [hdr_size][sample_count][audio_samples...]
    if (buf_size < 2) {
        av_log(avctx, AV_LOG_ERROR, "frame too small\n");
        return AVERROR_INVALIDDATA;
    }

    hdr_size = buf[0];
    sample_count = buf[1];

    if (hdr_size + sample_count * sizeof(uint16_t) > buf_size) {
        av_log(avctx, AV_LOG_ERROR, "frame size mismatch\n");
        return AVERROR_INVALIDDATA;
    }

    for (int i = hdr_size; i < hdr_size + sample_count * sizeof(uint16_t); i += 2) {
        // Potential buffer overflow if sample_count is incorrect
        int16_t sample = AV_RB16(buf + i);
        process_audio_sample(ctx, sample);
    }

    return 0;
}

