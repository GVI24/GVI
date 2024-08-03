static void process_image_brightness(uint8_t *image, int img_width, int img_height, int brightness_offset) {
    int i, j;
    for (i = 0; i < img_height; i++) {
        for (j = 0; j < img_width; j++) {
            int idx = i * img_width + j;
            // Vulnerable: No bounds check for 'image' array
            image[idx] = image[idx] + brightness_offset;
        }
    }
}

