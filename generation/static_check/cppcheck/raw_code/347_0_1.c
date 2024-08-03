static int decode_block_opcode_0xB(IpvideoContext *s) {
    int x, y;
    unsigned char colors[4];
    unsigned int flags;
    
    bytestream2_get_buffer(&s->stream_ptr, colors, sizeof(colors));
    flags = bytestream2_get_le32(&s->stream_ptr);
    
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++, flags >>= 1) {
            if ((x & 3) == 0) flags = bytestream2_get_le32(&s->stream_ptr);
            *s->pixel_ptr++ = colors[flags & 0x03];
        }
        s->pixel_ptr += s->stride - 8;
    }
    return 0;
}
