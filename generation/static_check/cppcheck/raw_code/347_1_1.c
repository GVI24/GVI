static int decode_block_opcode_0xC(IpvideoContext *s) {
    int y;
    unsigned char color;
    unsigned int line_flags;

    color = bytestream2_get_byte(&s->stream_ptr);
    line_flags = bytestream2_get_le32(&s->stream_ptr);
    
    for (y = 0; y < 16; y++) {
        memset(s->pixel_ptr, color, 8);
        s->pixel_ptr += s->stride;
        if ((y & 1) == 0) line_flags = bytestream2_get_le32(&s->stream_ptr);
    }
    return 0;
}
