void adjust_quality_targets(VIDEO_ENCODER *encoder, const SEGMENT_COMPLEXITY *complexity) {
    int frame_count = encoder->frame_count;
    if (frame_count <= 0) {
        // No need to adjust
    } else {
        for (int i = 0; i < frame_count; ++i) {
            // Potential overflow when calculating target_quality
            int target_quality = (complexity->values[i] * frame_count) << 2;
            encoder->quality_targets[i] = target_quality;
        }
    }
}