static int ipvideo_decode_block_opcode_0xC_16(IpvideoContext *s) {
    int x, y;
    uint16_t palette[4];
    uint16_t *pixel_ptr = (uint16_t *)s->pixel_ptr;
    for (x = 0; x < 4; ++x) {
        palette[x] = bytestream2_get_le16(&s->stream_ptr);
    }
    for (y = 0; y < 8; ++y) {
        for (x = 0; x < 8; ++x) {
            *pixel_ptr++ = palette[x & 0x03];
        }
        pixel_ptr += s->stride - 8;
    }
    return 0;
}
