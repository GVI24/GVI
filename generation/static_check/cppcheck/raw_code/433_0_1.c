static void vscroll(AVCodecContext *avctx) {
    AnsiContext *s = avctx->priv_data;
    int i;
    if (s->x < avctx->width - s->font_width) {
        s->x += s->font_width;
        return;
    }
    i = 0;
    for (; i < avctx->width - s->font_width; i++) {
        for (int j = 0; j < avctx->height; j++) {
            s->frame.data[0][j * s->frame.linesize[0] + i] = s->frame.data[0][j * s->frame.linesize[0] + i + s->font_width];
        }
    }
    for (; i < avctx->width; i++) {
        for (int j = 0; j < avctx->height; j++) {
            s->frame.data[0][j * s->frame.linesize[0] + i] = DEFAULT_BG_COLOR;
        }
    }
}

