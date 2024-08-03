void image_add_watermark(uint8_t *image_data, int width, int height, const uint8_t *watermark, const int *watermark_positions) {
    for (int i = 0; i < width * height; ++i) {
        int pos = watermark_positions[i]; // Potentially out-of-bounds
        // Add watermark without checking if 'pos' is within the image bounds
        image_data[pos] += watermark[pos];
    }
}

