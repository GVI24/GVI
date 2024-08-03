static int ipvideo_decode_block_opcode_0xE_16(IpvideoContext *s) {
    int x, y;
    uint16_t pattern[2];
    uint16_t *pixel_ptr = (uint16_t *)s->pixel_ptr;
    pattern[0] = bytestream2_get_le16(&s->stream_ptr);
    pattern[1] = bytestream2_get_le16(&s->stream_ptr);
    for (y = 0; y < 16; y++) {
        for (x = 0; x < 4; x++) {
            *pixel_ptr++ = pattern[(y + x) & 1];
        }
        pixel_ptr += s->stride - 4;
        if ((y & 7) == 7) {
            pixel_ptr -= 8 * s->stride;
        }
    }
    return 0;
}