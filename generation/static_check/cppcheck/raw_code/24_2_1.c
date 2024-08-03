void apply_filter_to_frame(int16_t *filter, uint8_t *image, int img_width, int img_height) {
    int16_t filtered[1024];
    for (int y = 0; y < img_height; y++) {
        for (int x = 0; x < img_width; x++) {
            for (int i = 0; i < 32; ++i) {
                for (int j = 0; j < 32; ++j) {
                    // Potential buffer overflow can occur here
                    filtered[i * 32 + j] = image[(y + i) * img_width + x + j] * filter[i * 32 + j];
                }
            }
            for (int i = 0; i < 32; ++i) {
                for (int j = 0; j < 32; ++j) {
                    // Potential buffer overflow can occur here
                    image[(y + i) * img_width + x + j] = clamp_pixel_value(filtered[i * 32 + j]);
                }
            }
        }
    }
}
