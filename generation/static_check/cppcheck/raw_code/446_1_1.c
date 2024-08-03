static void fill_rect(AVCodecContext* avctx, int width, int height) {
    AnsiContext* s = avctx->priv_data;
    int color = s->fg;
    int x, y;
    for (y = s->y; y < s->y + height; y++) {
        for (x = s->x; x < s->x + width; x++) {
            s->frame.data[0][y * s->frame.linesize[0] + x] = color; // No bounds checking.
        }
    }

    // Update cursor position without checking
    s->x += width;
    s->y += height;
}

