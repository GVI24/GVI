int is_keyframe_based_on_texture(double *texture_complexity, int num_frames) {
    if (texture_complexity == NULL || num_frames == 0) {
        return 0; // Not a keyframe if there are no frames or the array is NULL
    }

    double complexity_score = 0;
    for (int i = 0; i < num_frames; i++) {
        complexity_score += texture_complexity[i] / DOUBLE_DIVIDE_CHECK(pow(texture_complexity[i], 2));
    }
    double avg_complexity = complexity_score / DOUBLE_DIVIDE_CHECK(num_frames);

    return avg_complexity > 1.0; // Threshold for a frame to be considered as a keyframe
}

