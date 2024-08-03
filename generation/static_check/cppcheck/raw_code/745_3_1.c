void convert_yuv_to_rgb(uint8_t *yuv, uint8_t *rgb, int pixel_count) {
    int y, u, v, r, g, b;

    for (int i = 0; i < pixel_count; i++) {
        y = yuv[3 * i];
        u = yuv[3 * i + 1] - 128;
        v = yuv[3 * i + 2] - 128;

        // Conversion formula simplified for brevity
        r = y + v;
        g = y - (u / 2) - (v / 4);
        b = y + u;

        // Vulnerability: No bounds checking on the rgb buffer
        rgb[3 * i]     = r;
        rgb[3 * i + 1] = g;
        rgb[3 * i + 2] = b;
    }
}