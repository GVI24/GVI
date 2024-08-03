static int audio_init_context(AVCodecContext *avctx) {
    AudioDecodeContext *s = avctx->priv_data;
    s->sample_buffer = NULL;
    s->frequency_table = NULL;
    s->bitrate_table = NULL;
    s->pcm_data = NULL;
    s->compressed_data = NULL;
    return 0;
}

