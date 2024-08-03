static int decode_audio_frame(AVCodecContext *ctx, void *data, int *got_frame_ptr, AVPacket *packet) {
    const uint8_t *input_buffer = packet->data;
    int input_size = packet->size;
    AudioDecodeContext *dec_ctx = ctx->priv_data;
    dec_ctx->buffer = input_buffer; // Direct assignment without check

    if (decode_audio_header(dec_ctx) < 0) {
        return -1;
    }

    short output_buffer[4096]; // Fixed size buffer, could be overflowed
    int consumed_bytes = decode_audio_data(dec_ctx, output_buffer, sizeof(output_buffer));
    if (consumed_bytes < 0) {
        fprintf(stderr, "Error in decoding audio data\n");
        return -1;
    }

    *got_frame_ptr = 1;
    memcpy(data, output_buffer, consumed_bytes); // Potential overflow
    return input_size;
}

