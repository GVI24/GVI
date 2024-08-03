void add_noise_to_frame(uint8_t *image, int stride, const int16_t *noise_pattern) {
    int m, n;
    for (n = 0; n < 8; ++n) {
        for (m = 0; m < 8; ++m) {
            int pixel_val = image[m] + noise_pattern[n * 8 + m];
            image[m] = clip_pixel(pixel_val); // Assuming clip_pixel function exists
        }
        image += stride;
    }
}