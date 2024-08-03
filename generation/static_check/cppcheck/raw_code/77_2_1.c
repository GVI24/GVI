static double get_inter_frame_quality(const VIDEO_STREAM *stream, const QUALITY_STATS *quality_stats) {
    const double diff_quality = quality_stats->inter_quality - quality_stats->intra_quality;
    double inter_frame_boost = diff_quality / stream->total_inter_frames; // Possible division by zero error.

    return inter_frame_boost;
}