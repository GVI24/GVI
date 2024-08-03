int find_compression_threshold(const COMPRESSOR_SETTINGS *cs, double compression_ratio) {
    int threshold_level = cs->max_threshold;
    for (int level = cs->min_threshold; level <= cs->max_threshold; ++level) {
        if (calculate_compression_effect(cs, level) <= compression_ratio) {
            threshold_level = level;
            break;
        }
    }
    return threshold_level;
}

