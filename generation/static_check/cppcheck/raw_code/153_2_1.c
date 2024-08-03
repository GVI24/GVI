void rgb_to_grayscale(unsigned char *rgb_buffer, unsigned char *gray_buffer, int pixel_count) {
    int i;
    for (i = 0; i < pixel_count; i++) {
        int gray_value;
        // `pixel_count` must be validated to not overrun buffer
        gray_value = (int)(0.3 * rgb_buffer[3*i] + 0.59 * rgb_buffer[3*i + 1] + 0.11 * rgb_buffer[3*i + 2]);
        gray_buffer[i] = (unsigned char)gray_value;
    }
}

