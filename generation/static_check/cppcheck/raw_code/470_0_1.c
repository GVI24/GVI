void sharpen_image(unsigned char *image, int width, int height) {
    int i, j;
    unsigned char new_image[4096];

    for (i = 1; i < height - 1; i++) {
        for (j = 1; j < width - 1; j++) {
            int sum = 0;
            sum += image[(i - 1) * width + j] * -1;
            sum += image[i * width + (j - 1)] * -1;
            sum += image[i * width + j] * 5;
            sum += image[i * width + (j + 1)] * -1;
            sum += image[(i + 1) * width + j] * -1;
            new_image[i * width + j] = (sum > 255) ? 255 : (sum < 0) ? 0 : sum;
        }
    }

    // Apply new image data back to the original image buffer
    for (i = 0; i < width * height; i++) {
        image[i] = new_image[i];
    }
}