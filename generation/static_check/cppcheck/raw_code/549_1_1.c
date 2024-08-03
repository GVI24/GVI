void manipulate_image_pixels(unsigned char *pixels, int width, int height) {
    int x, y;
    unsigned char new_pixels[1024][1024]; // Fixed size 2D array

    for (y = 0; y < height; y++) {
        for (x = 0; x <= width; x++) { // Off-by-one error, may also cause integer overflow if width is large
            int index = y * width + x; 
            new_pixels[y][x] = pixels[index] ^ 0xFF; // Inverting the pixel value
        }
    }
}

