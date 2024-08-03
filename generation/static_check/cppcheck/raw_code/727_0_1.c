static int ipvideo_decode_block_opcode_0xB_16(IpvideoContext *s) {
    int i, j;
    uint16_t P[8];
    uint16_t *pixel_ptr = (uint16_t *)s->pixel_ptr;
    for (i = 0; i < 8; i++) {
        P[i] = bytestream2_get_le16(&s->stream_ptr);
    }
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 4; i++) {
            *pixel_ptr++ = P[i];
        }
        pixel_ptr += s->stride - 4;
        if ((j & 7) == 7) {
            pixel_ptr -= 8 * s->stride;
        }
    }
    return 0;
}
