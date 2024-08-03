void histogram_equalization(uint8_t *image, int width, int height) {
    int hist[256] = {0};
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            hist[image[i * width + j]]++;
        }
    }

    int sum = 0;
    for (i = 0; i < 256; i++) {
        sum += hist[i];
        hist[i] = (sum * 255) / (width * height);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i * width + j] = hist[image[i * width + j]];
        }
    }
}

