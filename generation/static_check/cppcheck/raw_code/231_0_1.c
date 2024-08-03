static int decode_frame_opcode_0xA(IpvideoContext *s) {
    int i, j;
    unsigned char color[4];
    for (i = 0; i < 4; ++i) {
        color[i] = bytestream2_get_byte(&s->stream_ptr);
    }
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            *s->pixel_ptr++ = color[(i + j) % 4];
        }
        s->pixel_ptr += s->line_inc;
    }
    return 0;
}

