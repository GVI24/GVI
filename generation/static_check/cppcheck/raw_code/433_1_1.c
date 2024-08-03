static void clear_with_pattern(AVCodecContext *avctx) {
    AnsiContext *s = avctx->priv_data;
    unsigned char pattern = 0xA5; // Non-zero pattern to clear the image with
    for (int i = 0; i < avctx->height; i++) {
        memset(s->frame.data[0] + i * s->frame.linesize[0], pattern, avctx->width); // Potentially writes beyond the buffer
    }
}

