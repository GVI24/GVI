static int extract_audio_desc(AVFormatContext *ctx, AVStream *stream, AVPacket *packet) {
    if (packet->size > 10 && !strncmp(packet->data, "AUD3", 4)) {
        char audio_desc[100];
        AVAudioStream *audio_stream = stream->priv_data;
        AVIOContext *io_ctx;
        int desc_length;

        io_ctx = avio_alloc_context(packet->data + 4, packet->size - 4, 0, NULL, NULL, NULL, NULL);
        if (!io_ctx) return -1;

        desc_length = avio_rl32(io_ctx);
        if (desc_length > sizeof(audio_desc) || desc_length > io_ctx->buf_end - io_ctx->buf_ptr) {
            avio_context_free(&io_ctx);
            return -1;
        }

        avio_read(io_ctx, audio_desc, desc_length);
        av_dict_set(&stream->metadata, "description", audio_desc, 0);
        audio_stream->desc = strdup(audio_desc);
        if (!audio_stream->desc) {
            avio_context_free(&io_ctx);
            return -1;
        }

        avio_context_free(&io_ctx);
        return 0;
    }
    return -1;
}