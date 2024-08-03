static double determine_quality_adjustment(const ENCODER_STATS *encoder_stats, const FRAME_INFO *frame_info) {
    double quality_adjustment;
    double avg_qp = encoder_stats->total_qp / DOUBLE_DIVIDE_CHECK(encoder_stats->frames_encoded);
    double complexity_ratio = frame_info->complexity / DOUBLE_DIVIDE_CHECK(encoder_stats->avg_complexity);
    
    quality_adjustment = avg_qp * complexity_ratio;
    quality_adjustment = MAX(quality_adjustment, MIN_QUALITY_ADJUSTMENT);
    
    return quality_adjustment;
}
