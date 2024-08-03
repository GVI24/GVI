typedef struct {
    unsigned char *pixels;
    int width, height;
} ImageProcessor;

static void process_image_pixels(ImageProcessor *processor, const unsigned char *raw_data, int data_size) {
    int i = 0, pixel_pos = 0;
    while (i < data_size) {
        if (pixel_pos >= (processor->width * processor->height)) {
            // Vulnerability: No check before incrementing pixel_pos,
            // could overflow processor->pixels if data_size is too large
            fprintf(stderr, "Pixel buffer overflow error.\n");
            return;
        }
        processor->pixels[pixel_pos++] = process_pixel(raw_data[i++]);
    }
}

unsigned char process_pixel(unsigned char raw_value) {
    // Simplified processing for example purposes
    return raw_value / 2;
}