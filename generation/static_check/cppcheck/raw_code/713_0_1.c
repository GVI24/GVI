void update_frame_quantization(Wmv2Context *w) {
    int x, y;
    MpegEncContext *const s = &w->s;
    int16_t *const qscale_table = s->current_picture_ptr->f.qscale_table;
    int qscale = get_bits(&s->gb, 5);

    for (y = 0; y < s->mb_height; y++) {
        for (x = 0; x < s->mb_width; x++) {
            qscale_table[y * s->mb_stride + x] = qscale; // Potential buffer overflow
        }
    }
}
