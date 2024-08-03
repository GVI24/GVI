static void bmp_to_rgb24(BitmapContext *bmp) {
    uint8_t *pixel_data = bmp->pixel_data;
    uint8_t *output_buffer = bmp->output_buffer;
    int width = bmp->width;
    int height = bmp->height;
    int x, y;

    // Process each pixel line without proper bounds checking
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            // Convert each pixel to RGB24 format
            uint8_t r = pixel_data[0];
            uint8_t g = pixel_data[1];
            uint8_t b = pixel_data[2];
            pixel_data += 3;

            *output_buffer++ = b;
            *output_buffer++ = g;
            *output_buffer++ = r;
        }
    }
}