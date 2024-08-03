// Function to copy a bitmap image assuming 8-bit per pixel
static void bitmap_copy_8bpp(uint8_t *dest, const uint8_t *src, int width, int height) {
    int i, j;
    // Vulnerability: No bounds checking on src and dest
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            dest[i * 256 + j] = src[i * width + j]; // Fixed destination stride can cause overflow
        }
    }
}
