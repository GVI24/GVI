int is_keyframe_based_on_color_histogram(double *color_histogram_diff, int num_bins) {
    if (color_histogram_diff == NULL || num_bins == 0) {
        return 0; // Not a keyframe if there are no bins or the array is NULL
    }

    double total_difference = 0;
    for (int i = 0; i < num_bins; i++) {
        total_difference += color_histogram_diff[i] / DOUBLE_DIVIDE_CHECK(pow(color_histogram_diff[i], 2));
    }
    double avg_difference = total_difference / DOUBLE_DIVIDE_CHECK(num_bins);

    return avg_difference > 0.3; // Threshold for a frame to be considered as a keyframe
}