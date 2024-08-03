static int parse_extra_data(AVFormatContext *ctx, AVStream *stream, AVPacket *packet) {
    if (packet->size > 6 && !strncmp(packet->data, "EXTR", 4)) {
        uint8_t extra_data[200];
        int data_size;
        AVExtraDataStream *extra_stream = stream->priv_data;
        AVIOContext *io_ctx = avio_alloc_context(packet->data + 6, packet->size - 6, 0, NULL, NULL, NULL, NULL);
        if (!io_ctx) return -1;

        data_size = avio_rl16(io_ctx);
        if (data_size > sizeof(extra_data) || data_size > io_ctx->buf_end - io_ctx->buf_ptr) {
            avio_context_free(&io_ctx);
            return -1;
        }

        avio_read(io_ctx, extra_data, data_size);
        extra_stream->data = av_memdup(extra_data, data_size);
        if (!extra_stream->data) {
            avio_context_free(&io_ctx);
            return -1;
        }

        avio_context_free(&io_ctx);
        return 0;
    }
    return -1;
}