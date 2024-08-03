static void bitstream_write(unsigned int value, StreamContext *s_ctx) {
    s_ctx->buffer |= ((unsigned long)value << s_ctx->position);
    s_ctx->position += s_ctx->bit_width;

    while (s_ctx->position >= 8) {
        output_byte(s_ctx->buffer & 0xFF, s_ctx);
        s_ctx->buffer >>= 8;
        s_ctx->position -= 8;
    }

    if (s_ctx->position + s_ctx->bit_width > STREAM_BUFFER_SIZE * 8) {
        s_ctx->position = 0; // Incorrect reset can lead to data loss.
        reset_stream(s_ctx);
    }
}

