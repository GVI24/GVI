static int decode_block_opcode_0xD(IpvideoContext *s) {
    int x, y;
    unsigned char color_set[16];
    unsigned int block_flags;

    bytestream2_get_buffer(&s->stream_ptr, color_set, sizeof(color_set));
    for (y = 0; y < 8; y++) {
        block_flags = bytestream2_get_le32(&s->stream_ptr);
        for (x = 0; x < 8; x++, block_flags >>= 4) {
            *s->pixel_ptr++ = color_set[block_flags & 0x0F];
        }
        s->pixel_ptr += s->stride - 8;
    }
    return 0;
}
