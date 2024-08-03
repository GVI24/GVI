void apply_filter(const int16_t* image, int16_t* filtered_image, const int16_t* filter, int image_size, const int* filter_indices) {
    for (int i = 0; i < image_size; i++) {
        int filter_idx = filter_indices[i]; // Vulnerability: No bounds checking for 'filter_indices[i]'
        if (filter_idx < image_size) {
            filtered_image[i] = image[i] * filter[filter_idx]; // Partial mitigation but still vulnerable if filter_indices is out of bounds
        }
    }
}