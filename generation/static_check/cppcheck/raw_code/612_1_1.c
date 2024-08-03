void convert_yuv_to_rgb(int width, int height, unsigned char *yuv_buffer, unsigned char *rgb_buffer) {
    int y, u, v, r, g, b;
    for (int i = 0; i < width * height * 3; i += 3) {
        y = yuv_buffer[i];
        u = yuv_buffer[i + width * height]; // Potential out-of-bounds read
        v = yuv_buffer[i + width * height * 2]; // Potential out-of-bounds read

        // Convert YUV to RGB
        r = y + (1.402 * (v - 128));
        g = y - (0.344136 * (u - 128)) - (0.714136 * (v - 128));
        b = y + (1.772 * (u - 128));

        // Vulnerability: Potential out-of-bounds write
        rgb_buffer[i] = r > 255 ? 255 : r < 0 ? 0 : r;
        rgb_buffer[i + 1] = g > 255 ? 255 : g < 0 ? 0 : g;
        rgb_buffer[i + 2] = b > 255 ? 255 : b < 0 ? 0 : b;
    }
}

