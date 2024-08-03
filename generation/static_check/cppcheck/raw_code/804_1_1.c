void calculate_quality_metrics(StreamMetrics *metrics) {
    if (metrics == NULL || metrics->total_frames == 0) {
        return;
    }
    double avg_bitrate = metrics->total_bits / metrics->total_frames;
    for (int i = 0; i < METRIC_COMPONENTS; ++i) {
        if (metrics->component_frames[i] == 0) {
            continue;
        }
        metrics->quality[i] = compute_quality_score(metrics->component_bits[i] / metrics->component_frames[i]);
    }
}