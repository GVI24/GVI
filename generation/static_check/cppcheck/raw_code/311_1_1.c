void process_image_pixels(int *image_data, int width, int height) {
    int processed_pixels[1024];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            processed_pixels[y * width + x] = image_data[y * width + x]; // Vulnerability: processed_pixels may be overflowed
        }
    }
}

