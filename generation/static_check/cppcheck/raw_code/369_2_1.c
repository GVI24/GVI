// Function to transpose a square matrix of 16-bit integers
static void transpose_matrix(uint16_t *dest, const uint16_t *src, int size) {
    int i, j;
    // Vulnerability: No bounds checking on src and dest
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            dest[j * size + i] = src[i * size + j]; // Potential overflow if dest buffer isn't properly allocated
        }
    }
}
