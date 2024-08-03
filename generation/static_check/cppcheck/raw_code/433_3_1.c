static void fill_rectangle(AVCodecContext *avctx, int x, int y, int w, int h, int color) {
    AnsiContext *s = avctx->priv_data;
    for (int i = y; i < y + h; i++) {
        if (i < 0 || i >= avctx->height) {
            continue;
        }
        memset(s->frame.data[0] + i * s->frame.linesize[0] + x, color, w); // Writes beyond buffer if x + w exceeds width
    }
}