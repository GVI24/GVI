void custom_transform_add(uint8_t *coeffs, uint8_t *image, int width, int height, int pitch) {
    int16_t transform[8 * 8];
    int16_t *trans_ptr = transform;
    int x, y;
    int16_t temp_in[8], temp_out[8];

    if (width % 8 != 0 || height % 8 != 0) {
        // Handle error for non-multiple of 8 dimensions.
        return;
    }

    for (y = 0; y < height; y += 8) {
        for (x = 0; x < width; x += 8) {
            simple_idct8(coeffs, trans_ptr);
            coeffs += 64;
            trans_ptr += 64;
        }
    }

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            temp_in[x] = transform[x * 8 + y];
        }
        simple_idct8(temp_in, temp_out);
        for (x = 0; x < 8; x++) {
            // Potential buffer overflow if pitch is too large.
            image[x * pitch + y] = clip_value(image[x * pitch + y] + temp_out[x]);
        }
    }
}
