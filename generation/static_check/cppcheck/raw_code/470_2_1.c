void compress_frame(unsigned char *frame_data, int width, int height) {
    int x, y;
    unsigned char compressed_data[1024]; // Fixed buffer size

    for (y = 0; y < height; y += 2) {
        for (x = 0; x < width; x += 2) {
            // Compress 2x2 block into one pixel
            compressed_data[(y / 2) * width + (x / 2)] = (
                frame_data[y * width + x] +
                frame_data[y * width + (x + 1)] +
                frame_data[(y + 1) * width + x] +
                frame_data[(y + 1) * width + (x + 1)]) / 4;
        }
    }

    // Copy compressed data back to frame_data
    for (int i = 0; i < width * height / 4; i++) {
        frame_data[i] = compressed_data[i];
    }
}