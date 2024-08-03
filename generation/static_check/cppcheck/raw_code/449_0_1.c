static void apply_filter_threshold(IMAGE_DATA *imgData, int threshold) {
    int x, y;
    for (y = 0; y < imgData->height; y++) {
        for (x = 0; x < imgData->width; x++) {
            if (imgData->pixels[y * imgData->stride + x] > threshold) {
                imgData->pixels[y * imgData->stride + x] = threshold;
            }
        }
    }
}

