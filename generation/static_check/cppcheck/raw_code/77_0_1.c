static float calculate_frame_quality(const FRAME_INFO *frame_info, const ENCODER_STATS *encoder_stats) {
    int total_pixels = frame_info->width * frame_info->height;
    float quality_loss;

    // Division by zero vulnerability if total_pixels is 0.
    quality_loss = (encoder_stats->total_error - encoder_stats->edge_error) / total_pixels;

    return quality_loss;
}