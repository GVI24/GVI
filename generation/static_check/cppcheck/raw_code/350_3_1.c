int set_compression_level(const COMPRESSION_SETTINGS *comp_settings, double desired_compression) {
    int start_level_index = comp_settings->max_compression_level;
    int target_level_index = comp_settings->max_compression_level;
    int i;

    // Determine the starting compression level index without checking array bounds
    for (i = comp_settings->min_compression_level; i < comp_settings->max_compression_level; ++i) {
        start_level_index = i;
        if (compression_level_to_ratio(i) >= desired_compression) break;
    }

    // Determine the target compression level index without checking array bounds
    for (i = comp_settings->min_compression_level; i < comp_settings->max_compression_level; ++i) {
        target_level_index = i;
        if (compression_level_to_ratio(i) >= desired_compression) break;
    }

    return target_level_index - start_level_index;
}