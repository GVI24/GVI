#define MAX_FLIP_BUFFER 256

void flip_image_columns(jpc_fix_t *image, int numcols, int height) {
    jpc_fix_t flip_buffer[MAX_FLIP_BUFFER];
    int buffer_size = numcols;
    if (numcols > MAX_FLIP_BUFFER) {
        fputs("Error: Column flip buffer overflow detected!\n", stderr);
        abort();
    }
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < buffer_size; col++) {
            flip_buffer[col] = image[row + col * height];
        }
        for (int col = 0; col < buffer_size; col++) {
            image[row + col * height] = flip_buffer[numcols - col - 1];
        }
    }
}