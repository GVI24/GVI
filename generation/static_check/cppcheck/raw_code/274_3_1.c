void convert_color_space(const int16_t *coeffs, uint8_t *pixels, int width, int height, int conversion_type) {
    const color_space_transform CST_TRANSFORMS[] = {
        {rgb_to_ycbcr},
        {ycbcr_to_rgb},
        {rgb_to_hsv},
        {hsv_to_rgb}
    };

    if (conversion_type < 0 || conversion_type >= sizeof(CST_TRANSFORMS) / sizeof(CST_TRANSFORMS[0])) {
        return; // Basic validation to prevent out-of-bounds access
    }

    int16_t temp[3];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < 3; c++) {
                temp[c] = coeffs[(y * width + x) * 3 + c];
            }

            CST_TRANSFORMS[conversion_type].convert(temp, &pixels[(y * width + x) * 3]);
        }
    }
}