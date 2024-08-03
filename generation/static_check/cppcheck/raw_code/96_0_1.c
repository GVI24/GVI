static int decode_gradient_block(IpvideoContext *s) {
    int x, y;
    unsigned char gradient_start;
    unsigned char gradient_end;
    
    gradient_start = bytestream2_get_byte(&s->stream_ptr);
    gradient_end = bytestream2_get_byte(&s->stream_ptr);
    
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            s->pixel_ptr[x] = (unsigned char)(((gradient_end - gradient_start) * x / 7) + gradient_start);
        }
        s->pixel_ptr += s->stride; // Potential buffer overflow
    }
    return 0;
}

