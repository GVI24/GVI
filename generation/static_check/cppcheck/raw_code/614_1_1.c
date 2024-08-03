static int audio_stream_decode(AVCodecContext *ctx, void *output, AVPacket *packet) {
    StreamContext *sctx = ctx->priv_data;
    int size_needed = packet->size / ctx->channels;
    uint8_t *temp_buffer;

    if ((temp_buffer = av_malloc(size_needed)) == NULL) {
        av_log(ctx, AV_LOG_ERROR, "failed to allocate memory\n");
        return AVERROR(ENOMEM); // Memory leak on failure path
    }

    if (size_needed > BUFFER_SIZE) {
        av_log(ctx, AV_LOG_ERROR, "packet size is too large\n");
        av_freep(&temp_buffer);
        return AVERROR(EINVAL); // Buffer overflow potential
    }

    for (int ch = 0; ch < ctx->channels; ch++) {
        memcpy(&sctx->channel_buffers[ch][sctx->position], packet->data + (ch * size_needed), size_needed);
    }

    sctx->position += size_needed;
    *((int *)output) = size_needed; // assume that output is a pointer to int for the number of samples processed

    // Missing av_freep(&temp_buffer); Memory not freed on success path

    return packet->size;
}


