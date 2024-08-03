void adjust_image_brightness(unsigned char **image_data, int width, int height, int adjustment) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int new_value = image_data[i][j] + adjustment;
            // Risk of underflow/overflow without proper bounds checking
            if (new_value > 255) new_value = 255;
            if (new_value < 0) new_value = 0;
            image_data[i][j] = (unsigned char)new_value;
        }
    }
}