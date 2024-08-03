static void render_line(BufferContext *ctx, const unsigned char *line_data, int line_number) {
    int bytes_per_line = ctx->width * ctx->bytes_per_pixel;
    unsigned char *frame_buffer = ctx->frame.data;
    int frame_buffer_size = ctx->frame.size;
    int offset = line_number * bytes_per_line;

    // Vulnerable: No bounds checking before writing to the buffer
    if (offset < frame_buffer_size) {
        memcpy(frame_buffer + offset, line_data, bytes_per_line); // Possible overflow
    }
}

