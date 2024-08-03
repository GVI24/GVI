static int apply_filter_to_block(IpvideoContext *s, unsigned char filter_value) {
    int x, y;
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 4; x++) {
            // Apply filter value to every two pixels
            s->pixel_ptr[2 * x]     = filter_value;
            s->pixel_ptr[2 * x + 1] = s->pixel_ptr[2 * x + 1] / 2 + filter_value / 2;
        }
        s->pixel_ptr += s->stride; // Potential buffer overflow
    }
    return 0;
}