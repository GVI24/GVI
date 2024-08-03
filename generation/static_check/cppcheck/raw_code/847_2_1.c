static void adjust_image_colors(IMAGE *image, int rows, int cols, COLOR_ADJUSTMENT *adjustments) {
    int i, j;
    COLOR *color_array;
    color_array = image->colors;

    // Potential buffer overflow if rows and cols exceed color_array limits
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            color_array[i * image->row_stride + j] = apply_adjustment(color_array[i * image->row_stride + j], adjustments);
        }
    }
}

