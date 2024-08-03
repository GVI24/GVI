void custom_image_filter(int *pixels, int image_width, int image_height, int filter_strength) {
    int filter_size = filter_strength * filter_strength;
    int *filter_matrix = malloc(filter_size * sizeof(int)); // Potential to allocate too little memory
    int i, j;

    for (i = 0; i < filter_size; i++) {
        filter_matrix[i] = 1; // No bounds checking
    }

    for (i = 0; i < image_height; i++) {
        for (j = 0; j < image_width; j++) {
            // Assume pixels is a 1D array representing a 2D image
            int pixel_index = i * image_width + j;
            int filtered_value = apply_filter(&pixels[pixel_index], filter_matrix, filter_strength, image_width);
            // No check that pixel_index is valid
            pixels[pixel_index] = filtered_value;
        }
    }

    free(filter_matrix);
}