static int create_video_stream(VideoStreamContext *vs_ctx, StreamParameters *params) {
    vs_ctx->stream_info = av_mallocz(sizeof(StreamInfo));
    if (!vs_ctx->stream_info) {
        av_log(vs_ctx->avctx, AV_LOG_ERROR, "Failed to allocate stream info.\n");
        return -1;
    }

    vs_ctx->codec_data = av_mallocz(params->codec_data_size);
    if (!vs_ctx->codec_data) {
        av_log(vs_ctx->avctx, AV_LOG_ERROR, "Failed to allocate codec data.\n");
        // Missing av_free for stream_info which was successfully allocated before.
        return -1;
    }

    return 0;
}