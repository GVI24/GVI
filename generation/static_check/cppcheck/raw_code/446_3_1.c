static void draw_vertical_line(AVCodecContext* avctx, int height) {
    AnsiContext* s = avctx->priv_data;
    int color = s->fg;
    if ((s->attributes & ATTR_BLINK)) color += 8;

    for (int i = 0; i < height; i++) {
        int y_pos = s->y + i;
        if (y_pos >= avctx->height) break; // A naive attempt at bounds checking.
        s->frame.data[0][y_pos * s->frame.linesize[0] + s->x] = color;
    }
    // Improperly updating the position without height checking.
    s->y += height; // This can cause 'y' to exceed the frame height.
}