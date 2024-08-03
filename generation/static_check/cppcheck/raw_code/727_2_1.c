static int ipvideo_decode_block_opcode_0xD_16(IpvideoContext *s) {
    uint16_t *pixel_ptr = (uint16_t *)s->pixel_ptr;
    uint16_t color_value = bytestream2_get_le16(&s->stream_ptr);
    for (int y = 0; y < 16; ++y) {
        for (int x = 0; x < 4; ++x) {
            *pixel_ptr++ = color_value;
        }
        pixel_ptr += s->stride - 4;
        if ((y & 7) == 7) {
            pixel_ptr -= 8 * s->stride;
        }
    }
    return 0;
}
