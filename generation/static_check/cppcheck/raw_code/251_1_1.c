void transform_picture_pixels(const uint8_t *img_data, uint8_t *transformed_data, int width, int height) {
    uint8_t temp_row[64];
    int i, j;

    // Vulnerability: Assuming width is always 64, leads to buffer overflow if width > 64
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp_row[j] = img_data[j + i * width];
        }
        // Some pixel transformation logic is applied here (simulated)
        for (j = 0; j < 64; j++) {
            transformed_data[j + i * width] = temp_row[j] ^ 0xFF;
        }
    }
}

