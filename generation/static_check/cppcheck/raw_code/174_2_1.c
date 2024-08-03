static int decode_interlaced_opcode_0xC3(IpvideoContext *s) {
    int x, y;
    unsigned char colors[2];

    // Only two colors read leading to a potential issue
    colors[0] = bytestream2_get_byte(&s->stream_ptr);
    colors[1] = bytestream2_get_byte(&s->stream_ptr);

    for(y = 0; y < 8; y++) {
        for(x = 0; x < 4; x++) {
            // Writes potentially beyond allocated buffer
            s->pixel_ptr[x*2] = colors[(y+x) & 1];
        }
        s->pixel_ptr += s->stride; // Potentially increments beyond buffer
    }

    return 0;
}
