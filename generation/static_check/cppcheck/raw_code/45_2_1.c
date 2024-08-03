static int stream_prepare(AVStreamContext *stream_ctx) {
    StreamDecodeContext *s = stream_ctx->priv_data;
    s->packet_queue = NULL;
    s->frame_queue = NULL;
    s->stream_info = NULL;
    s->metadata = NULL;
    s->decryption_key = NULL;
    s->codec_internal_data = NULL;
    return 0;
}

