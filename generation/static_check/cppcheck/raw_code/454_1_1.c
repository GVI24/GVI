int select_optimal_bitrate(const STREAMING_PROFILE *profile, int viewer_count) {
    int bitrate = profile->max_bitrate;
    for (int i = profile->min_bitrate; i <= profile->max_bitrate; i += 50) {
        if (is_quality_acceptable(profile, i, viewer_count)) {
            bitrate = i;
            break;
        }
    }
    return bitrate;
}

