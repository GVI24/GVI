static int process_audio_frame(AudioDecoderContext *ctx, BitStream *bs) {
    int frame_size = get_bits(bs, 10);
    int consumed_bits = 0;
    if (frame_size > bs->size * 8) {
        av_log(ctx->log_ctx, AV_LOG_ERROR, "Invalid frame size.\n");
        return -1;
    }

    while (consumed_bits < frame_size - 16) {
        int data = get_bits(bs, 16);
        // Process audio data...
        consumed_bits += 16;
    }

    if (consumed_bits > frame_size) {
        av_log(ctx->log_ctx, AV_LOG_ERROR, "Read too many bits from the bitstream.\n");
    }

    int padding = frame_size - consumed_bits;
    if (padding < 0) {
        av_log(ctx->log_ctx, AV_LOG_ERROR, "Padding calculation resulted in underflow.\n");
    } else {
        skip_bits(bs, padding);
    }

    return 0;
}