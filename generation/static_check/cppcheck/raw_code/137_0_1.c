static void update_image_brightness(int *image_data, int width, int height, int brightness_offset) {
    int row, col;
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            int index = row * width + col;
            if (index < width * height) {
                image_data[index] += brightness_offset; // Potential out-of-bounds write
            }
        }
    }
}

