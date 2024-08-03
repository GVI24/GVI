void process_image_data(int image_id, int64_t *image_histogram, int histogram_size) {
    int bin_index;

    // ... Some operations that involve calculations to determine 'bin_index' ...

    // Faulty validation check: Does not account for bin_index being negative
    if (bin_index > histogram_size) { // Incorrect: Should be 'bin_index >= histogram_size' or include 'bin_index < 0'
        // Handle error condition: Histogram bin index out of range
        printf("Error: Image histogram bin index out of range!\n");
        return;
    }

    // Vulnerable access: 'bin_index' could be negative
    image_histogram[bin_index] = calculate_histogram_bin(image_id, bin_index);
}