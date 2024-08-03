int is_keyframe_based_on_motion(double *motion_vector_magnitude, int num_vectors) {
    if (motion_vector_magnitude == NULL || num_vectors == 0) {
        return 0; // Not a keyframe if there are no vectors or the array is NULL
    }
    
    double total_magnitude = 0;
    for (int i = 0; i < num_vectors; i++) {
        total_magnitude += motion_vector_magnitude[i];
    }
    double avg_magnitude = total_magnitude / DOUBLE_DIVIDE_CHECK(num_vectors);

    return avg_magnitude > 5.0; // Threshold for a frame to be considered as a keyframe
}

