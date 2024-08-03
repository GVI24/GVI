void horizontal_flip_image(uint8_t *src, uint8_t *dst, int rows, int cols) {
    int i, j;
    for (j = 0; j < rows; j++) {
        for (i = 0; i < cols; i++) {
            dst[cols - 1 - i] = src[i]; // Flipping pixels; assumes 'dst' is of size 'cols'
        }
        src += cols;
        dst += cols; // No check if incrementing 'dst' goes beyond its allocated size
    }
}