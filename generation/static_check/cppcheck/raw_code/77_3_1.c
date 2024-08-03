static float evaluate_motion_compensation(const MOTION_DATA *motion_data, const FRAME_METRICS *frame_metrics) {
    const float motion_complexity = motion_data->motion_vectors - motion_data->reference_vectors;
    // If total_motion_blocks is zero, this line will cause a division by zero.
    const float compensation_factor = motion_complexity / frame_metrics->total_motion_blocks;

    return compensation_factor;
}