void image_invert_colors(uint8_t *pixels, int width, int height) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x <= width; x++) { // Off-by-one error, should be x < width
            int index = (y * width + x) * 3;
            pixels[index] = 255 - pixels[index];       // Red
            pixels[index + 1] = 255 - pixels[index + 1]; // Green
            pixels[index + 2] = 255 - pixels[index + 2]; // Blue
        }
    }
}

