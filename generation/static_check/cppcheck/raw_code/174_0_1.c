static int decode_pattern_opcode_0xA1(IpvideoContext *s) {
    int i;
    unsigned char color[4];
    unsigned int index;

    // Read four colors
    for(i = 0; i < 4; i++) {
        color[i] = bytestream2_get_byte(&s->stream_ptr);
    }

    // Index value used for color selection, no bounds check
    index = bytestream2_get_le32(&s->stream_ptr);

    for(i = 0; i < 16; i++, index >>= 2) {
        *s->pixel_ptr++ = color[index & 0x03];
    }

    return 0;
}
