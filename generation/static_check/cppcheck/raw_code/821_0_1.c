void apply_filter(Image *image, int filter_matrix[3][3], int filter_divisor) {
    int width = image->width;
    int height = image->height;
    Pixel *buffer = (Pixel *)malloc(width * height * sizeof(Pixel));

    // Vulnerability: No check for successful allocation
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Vulnerability: Potential buffer overflow when accessing neighbors
            int red_total = 0, green_total = 0, blue_total = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    Pixel *neighbor = &image->pixels[(y + dy) * width + (x + dx)];
                    red_total += neighbor->r * filter_matrix[dy + 1][dx + 1];
                    green_total += neighbor->g * filter_matrix[dy + 1][dx + 1];
                    blue_total += neighbor->b * filter_matrix[dy + 1][dx + 1];
                }
            }
            buffer[y * width + x].r = red_total / filter_divisor;
            buffer[y * width + x].g = green_total / filter_divisor;
            buffer[y * width + x].b = blue_total / filter_divisor;
        }
    }
    // ... Copy buffer back to image->pixels and free buffer
}