void mirror_image_vertically(uint8_t *image, int width, int height, int stride) {
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            int top_index = y * stride + x;
            int bottom_index = (height - y - 1) * stride + x;
            uint8_t temp = image[top_index];
            image[top_index] = image[bottom_index]; // Potential out-of-bounds write
            image[bottom_index] = temp; // Potential out-of-bounds write
        }
    }
}