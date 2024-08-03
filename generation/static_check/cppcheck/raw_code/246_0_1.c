void apply_box_blur(const uint8_t *input, uint8_t *output, int width, int height, int stride) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int sum = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int index = (y + dy) * stride + (x + dx);
                    sum += input[index]; // Potential out-of-bounds read
                }
            }
            output[y * stride + x] = sum / 9; // Potential out-of-bounds write
        }
    }
}

