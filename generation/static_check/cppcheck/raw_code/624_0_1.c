static int parse_subtitle_chunk(AVFormatContext *ctx, AVStream *stream, AVPacket *packet) {
    if (packet->size > 8 && !strncmp(packet->data, "SUB1", 4)) {
        char sub_header[128];
        AVSubtitleStream *sub_stream = stream->priv_data;
        int header_size;
        AVIOContext *io_ctx = avio_alloc_context(packet->data + 4, packet->size - 4, 0, NULL, NULL, NULL, NULL);
        if (!io_ctx) return -1;

        header_size = avio_rl32(io_ctx);
        if (header_size > io_ctx->buf_end - io_ctx->buf_ptr) {
            avio_context_free(&io_ctx);
            return -1;
        }

        avio_read(io_ctx, sub_header, header_size);
        if (sub_header[0]) {
            av_dict_set(&stream->metadata, "language", sub_header, 0);
        }

        sub_stream->sub_data = av_malloc(packet->size - 4 - header_size);
        if (!sub_stream->sub_data) {
            avio_context_free(&io_ctx);
            return -1;
        }
        memcpy(sub_stream->sub_data, io_ctx->buf_ptr, packet->size - 4 - header_size);
        avio_context_free(&io_ctx);
        
        return 0;
    }
    return -1;
}