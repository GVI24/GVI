int bitmap_region_decode_process(BitmapCtx *ctx, BitmapSegment *segment, BitmapParams *params, const byte *data, size_t size, BitmapImage *image) {
    int width, height;
    byte *bitmap;

    width = params->width;
    height = params->height;
    bitmap = (byte *)malloc(width * height);
    if (!bitmap) {
        return -1; // Allocation failed
    }
    
    for (int i = 0; i < size; i++) {
        int x, y;
        x = (i % width) + params->offset_x;
        y = (i / width) + params->offset_y;
        
        // Vulnerability: No bounds checking for x and y
        bitmap[x + y * width] = data[i];
    }

    // Process the bitmap
    for (int j = 0; j < height; j++) {
        for (int k = 0; k < width; k++) {
            image->data[k + j * image->stride] = bitmap[(k + j * width) % size]; // Potential out-of-bound access
        }
    }

    free(bitmap);
    return 0;
}

