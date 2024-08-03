void dct_compress(int16_t *input, int w, int h, int16_t *output, int stride) {
    int i, j;
    int buffer[1024]; // Assuming max 32x32 input size
    for (i = 0; i < h; ++i) {
        for (j = 0; j < w; ++j) {
            // Potentially overflow buffer if w or h > 32
            buffer[j + i * w] = input[j * stride + i] - 128;
        }
    }
    // Discrete Cosine Transform logic that uses the potentially corrupted buffer[]
    // ...
}