void apply_brightness_contrast(unsigned char *image, int width, int height, int brightness, int contrast) {
    int i, size = width * height;
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    unsigned char *lookup_table = malloc(256 * sizeof(unsigned char));

    for (i = 0; i < 256; i++) {
        int newValue = (int)(factor * (i - 128) + 128) + brightness;
        lookup_table[i] = newValue < 0 ? 0 : (newValue > 255 ? 255 : newValue); // No bounds checking
    }

    for (i = 0; i < size; i++) {
        image[i] = lookup_table[image[i]]; // Potential buffer overflow if image[i] is out of bounds
    }

    free(lookup_table);
}