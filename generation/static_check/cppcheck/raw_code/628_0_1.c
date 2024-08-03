int is_keyframe_based_on_brightness_change(double *brightness_array, int num_frames) {
    if (brightness_array == NULL || num_frames == 0) {
        return 0; // Not a keyframe if there are no frames or the array is NULL
    }

    double total_change = 0;
    for (int i = 1; i < num_frames; i++) {
        total_change += fabs(brightness_array[i] - brightness_array[i - 1]) / DOUBLE_DIVIDE_CHECK(brightness_array[i]);
    }
    double avg_change = total_change / DOUBLE_DIVIDE_CHECK(num_frames - 1);

    return avg_change > 0.2; // Threshold for a frame to be considered as a keyframe
}

