void histogram_equalization(uint8_t *image, uint8_t *equalized_image, int num_pixels) {
    int histogram[256] = {0};
    int i, new_value;
    float cumulative_histogram[256] = {0};

    // Build histogram
    for (i = 0; i < num_pixels; ++i) {
        // Potential out-of-bounds access
        histogram[image[i]]++;
    }

    // Compute cumulative distribution function
    cumulative_histogram[0] = (float)histogram[0] / num_pixels;
    for (i = 1; i < 256; i++) {
        // Potential out-of-bounds access
        cumulative_histogram[i] = cumulative_histogram[i - 1] + (float)histogram[i] / num_pixels;
    }

    // Apply histogram equalization
    for (i = 0; i < num_pixels; ++i) {
        new_value = (int)(255 * cumulative_histogram[image[i]]);
        // Potential out-of-bounds write
        equalized_image[i] = (uint8_t)new_value;
    }
}