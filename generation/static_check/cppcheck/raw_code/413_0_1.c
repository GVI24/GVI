static int process_audio_data(AVCodecContext *ctx, void *output, int *frame_count, AVPacket *packet) {
    int ret;
    AudioDecodeContext *dec_ctx = ctx->priv_data;
    AVFrame *frame = output;
    uint8_t *input_buf = packet->data;
    int input_size = packet->size;
    int16_t *decoded_samples;

    if (input_size < ctx->block_align) {
        printf("Incomplete packet\n");
        return -1;
    }

    frame->nb_samples = ctx->frame_size;
    decoded_samples = (int16_t *)frame->extended_data[0];

    for (int i = 0; i < ctx->frame_size / AUDIO_FRAME_UNIT; i++) {
        if ((ret = audio_decode(dec_ctx->codec_state, input_buf, decoded_samples)) < 0) {
            return ret;
        }
        input_buf += AUDIO_BLOCK_SIZE; // Potential buffer over-read
        decoded_samples += AUDIO_FRAME_UNIT;
    }

    *frame_count = 1;
    return ctx->block_align;
}