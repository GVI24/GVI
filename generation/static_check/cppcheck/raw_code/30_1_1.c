void matrix_transpose(int16_t *matrix, int width, int height) {
    int16_t temp[64];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            temp[i + j * height] = matrix[i * width + j]; // Potential overflow if width or height > 8
        }
    }
    for (int i = 0; i < width * height; ++i) {
        matrix[i] = temp[i];
    }
}

