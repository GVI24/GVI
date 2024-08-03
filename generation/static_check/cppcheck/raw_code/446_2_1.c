static void copy_to_frame(AVCodecContext* avctx, const uint8_t* data, int size) {
    AnsiContext* s = avctx->priv_data;
    uint8_t* frame_buffer = s->frame.data[0] + s->y * s->frame.linesize[0] + s->x;

    memcpy(frame_buffer, data, size); // Directly copying without bounds checking.

    // Update the drawing position arbitrarily
    s->x += size; // Might cause 'x' to exceed the frame width.
    if (s->x >= avctx->width) {
        s->x = 0;
        s->y++; // Might cause 'y' to exceed the frame height.
    }
}

