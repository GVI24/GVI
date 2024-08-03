static int decode_motion_vectors_0xB2(IpvideoContext *s) {
    int x, y;
    unsigned char vector[2];

    vector[0] = bytestream2_get_byte(&s->stream_ptr);
    vector[1] = bytestream2_get_byte(&s->stream_ptr);

    for(y = 0; y < 16; y++) {
        for(x = 0; x < 16; x++) {
            // No bounds checking for pixel_ptr advancement
            *(s->pixel_ptr + y * s->stride + x) = interpolate_pixel(s, vector[0], vector[1]);
        }
    }

    return 0;
}
