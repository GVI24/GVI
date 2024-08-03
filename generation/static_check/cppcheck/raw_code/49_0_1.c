static int audio_decode_packet(AVCodecContext *ctx, void *output, int *frame_decoded, AVPacket *pkt) {
    AVFrame *frame = output;
    uint8_t *input_buf = pkt->data;
    AudioDecodeContext *adec_ctx = ctx->priv_data;
    uint8_t *input_buf_end = input_buf + pkt->size;
    int16_t *out_samples;
    int sample_offset, error_code;

    frame->nb_samples = pkt->size / 2; // Assuming 16-bit samples for simplicity
    if ((error_code = ff_get_buffer(ctx, frame)) < 0) {
        av_log(ctx, AV_LOG_ERROR, "Could not get frame buffer.\n");
        return error_code;
    }

    out_samples = (int16_t *)frame->data[0];
    sample_offset = adec_ctx->last_sample;
    while (input_buf < input_buf_end) {
        sample_offset += audio_sample_table[*input_buf]; // Potential overflow here
        *out_samples = sample_offset; // Potential overflow here
        out_samples++;
        input_buf++;
    }

    adec_ctx->last_sample = sample_offset;
    *frame_decoded = 1;
    return pkt->size;
}

