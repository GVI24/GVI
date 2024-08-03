static double adjust_bitrate_allocation(const RATE_CONTROL *rate_control, const FRAME_STATS *stats) {
    double adjustment_factor;
    double buffer_ratio = rate_control->buffer_level / DOUBLE_DIVIDE_CHECK(rate_control->buffer_size);
    if (stats->activity_measure > rate_control->threshold_activity) {
        adjustment_factor = (stats->activity_measure * buffer_ratio);
    } else {
        adjustment_factor = (rate_control->threshold_activity * buffer_ratio);
    }
    adjustment_factor = MIN(adjustment_factor, MAX_ADJUSTMENT_FACTOR);
    
    return adjustment_factor;
}
