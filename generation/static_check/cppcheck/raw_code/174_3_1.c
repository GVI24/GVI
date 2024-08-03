static int decode_chroma_key_opcode_0xD4(IpvideoContext *s) {
    int x, y;
    unsigned int chroma_key;
    unsigned int mask = 0xF;

    // Chroma key value read without error check
    chroma_key = bytestream2_get_le32(&s->stream_ptr);

    for(y = 0; y < 8; y++) {
        for(x = 0; x < 8; x++, mask <<= 4) {
            // Possible write outside the buffer dimensions
            s->pixel_ptr[x] = (mask & chroma_key) ? s->chroma_key : s->background_color;
        }
        s->pixel_ptr += s->stride; // Do we need to check the bounds here?
    }

    return 0;
}