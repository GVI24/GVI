static int decode_block_opcode_0xE(IpvideoContext *s) {
    int i;
    unsigned char colors[256];
    unsigned int index;

    bytestream2_get_buffer(&s->stream_ptr, colors, sizeof(colors));
    for (i = 0; i < 256; i++) {
        index = bytestream2_get_byte(&s->stream_ptr);
        *s->pixel_ptr++ = colors[index];
        if ((i & 15) == 15) s->pixel_ptr += s->stride - 16;
    }
    return 0;
}