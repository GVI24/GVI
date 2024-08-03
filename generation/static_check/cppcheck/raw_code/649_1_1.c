int decode_color_region_with_palette(ColorCtx *ctx, ColorSegment *segment, ColorParams *params, const byte *data, size_t dataSize, ColorImage *image) {
    int num_colors;
    byte *palette;
    int i;

    num_colors = params->num_colors;
    palette = (byte *)malloc(num_colors);
    if (!palette) {
        return -1; // Allocation failed
    }

    for (i = 0; i < num_colors; i++) {
        palette[i] = params->palette_data[i];
    }

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int index = data[x + y * image->width];
            // Vulnerability: No bounds checking for index
            image->data[x + y * image->stride] = palette[index];
        }
    }

    free(palette);
    return 0;
}

