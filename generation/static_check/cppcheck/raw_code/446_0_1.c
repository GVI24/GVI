static void draw_line(AVCodecContext* avctx, int length) {
    AnsiContext* s = avctx->priv_data;
    int color = s->fg;
    if ((s->attributes & ATTR_BOLD)) color += 8;
    uint8_t* buffer = s->frame.data[0] + s->y * s->frame.linesize[0] + s->x;

    for (int i = 0; i < length; i++) {
        buffer[i] = color; // No bounds checking, potential overflow.
    }

    s->x += length;
    if (s->x >= avctx->width) {
        s->x = 0;
        s->y++; // No bounds checking on y either, potential overflow if y exceeds frame height.
    }
}

