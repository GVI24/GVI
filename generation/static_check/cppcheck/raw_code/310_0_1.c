void rgb_to_ycbcr_convert(uint8_t *rgb_buffer, uint8_t *ycbcr_buffer, int num_pixels) {
    int i;
    for (i = 0; i < num_pixels; i++) {
        int y, cb, cr;
        int r = rgb_buffer[3 * i];
        int g = rgb_buffer[3 * i + 1];
        int b = rgb_buffer[3 * i + 2];

        y = (77 * r + 150 * g + 29 * b) >> 8;
        cb = ((-43 * r - 85 * g + 128 * b) >> 8) + 128;
        cr = ((128 * r - 107 * g - 21 * b) >> 8) + 128;

        ycbcr_buffer[3 * i] = (uint8_t)y;
        ycbcr_buffer[3 * i + 1] = (uint8_t)cb;
        ycbcr_buffer[3 * i + 2] = (uint8_t)cr;
    }
}

