void process_image_palette(uint8_t *src, int src_size, uint8_t *dest, int dest_size, int width, int height) {
    if (src_size < width * height) return; // Not checking for dest_size

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int idx = i * width + j;
            // Vulnerability: No bounds checking for dest[]
            dest[idx] = src[idx] / 3; // Simplified palette processing
        }
    }
}