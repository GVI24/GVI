void process_image_pixels(uint8_t *image, int width, int height) {
    int x, y;
    for (y = 0; y <= height; y++) { // Off-by-one error could overflow the buffer
        for (x = 0; x < width; x++) {
            // No check on image buffer size
            uint8_t pixel = image[y * width + x];
            // Some image processing that could cause an overflow
            image[y * width + x] = pixel_process(pixel);
        }
    }
}

uint8_t pixel_process(uint8_t pixel) {
    // Some dummy pixel processing logic
    return pixel ^ 0xFF; // Just inverts the pixel value for the sake of example
}