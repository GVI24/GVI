static double compute_bitrate_adjustment(const VIDEO_PARAMS *video_params, const BITRATE_STATS *bitrate_stats) {
    const double frame_size_delta = bitrate_stats->frame_size - bitrate_stats->expected_size;
    const double adjustment_factor = frame_size_delta / video_params->frame_count; // Potential division by zero.

    return adjustment_factor;
}