void count_pixel_formats(Pixel *pixels, int width, int height, int format_count[PIXEL_FORMATS]) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int format = pixels[x + y * width].format;
            // Potential out-of-bounds array access.
            format_count[format]++;
        }
    }
}

