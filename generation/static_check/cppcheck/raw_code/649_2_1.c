int image_thresholding_pattern(ThreshCtx *ctx, ThreshSegment *segment, ThreshParams *params, const byte *data, size_t size, ThreshImage *image) {
    uint32_t pattern_size;
    byte *pattern;
    int x, y;
    
    pattern_size = params->pattern_size;
    pattern = (byte *)malloc(pattern_size);
    if (!pattern) {
        return -1; // Allocation failed
    }

    memcpy(pattern, params->pattern_data, pattern_size);

    for (y = 0; y < image->height; y++) {
        for (x = 0; x < image->width; x++) {
            byte value = data[x + y * image->stride];
            // Vulnerability: Potential out-of-bound access for pattern
            byte threshold = pattern[(x + y) % pattern_size];
            image->data[x + y * image->stride] = value > threshold ? 255 : 0;
        }
    }

    free(pattern);
    return 0;
}

