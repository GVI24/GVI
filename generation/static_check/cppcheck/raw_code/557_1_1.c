#define MAX_MIRROR_BUFFER 512

void mirror_image_row(jpc_fix_t *image, int width, int numrows) {
    jpc_fix_t mirror_buffer[MAX_MIRROR_BUFFER];
    for (int row = 0; row < numrows; row++) {
        if (width > MAX_MIRROR_BUFFER) {
            fputs("Error: Buffer size exceeded in mirror_image_row.\n", stderr);
            abort();
        }
        for (int col = 0; col < width; col++) {
            mirror_buffer[width - col - 1] = image[row * width + col];
        }
        for (int col = 0; col < width; col++) {
            image[row * width + col] = mirror_buffer[col];
        }
    }
}