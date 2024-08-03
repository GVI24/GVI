int grayscale_to_halftone(GrayCtx *ctx, GraySegment *segment, GrayParams *params, const byte *data, size_t size, GrayImage *image) {
    byte *halftone;
    int x, y;

    halftone = (byte *)malloc(image->width * image->height);
    if (!halftone) {
        return -1; // Allocation failed
    }

    for (y = 0; y < image->height; y++) {
        for (x = 0; x < image->width; x++) {
            byte intensity = data[x + y * image->stride]; // Vulnerability: No bounds checking for data array
            // Simple halftone effect based on intensity thresholding
            halftone[x + y * image->width] = (intensity / params->threshold) % 2 ? 255 : 0;
        }
    }

    memcpy(image->data, halftone, image->width * image->height);
    free(halftone);
    return 0;
}