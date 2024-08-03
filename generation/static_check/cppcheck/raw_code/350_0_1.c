int compute_optimal_bitrate(const ENCODER_STATE *encoder, double min_bitrate, double max_bitrate) {
    int min_index = encoder->max_bitrate_setting;
    int max_index = encoder->max_bitrate_setting;
    int i;

    // Find the minimum bitrate index without proper bounds checking
    for (i = encoder->min_bitrate_setting; i < encoder->max_bitrate_setting; ++i) {
        min_index = i;
        if (convert_index_to_bitrate(i) >= min_bitrate) break;
    }

    // Find the maximum bitrate index without proper bounds checking
    for (i = encoder->min_bitrate_setting; i < encoder->max_bitrate_setting; ++i) {
        max_index = i;
        if (convert_index_to_bitrate(i) >= max_bitrate) break;
    }

    return max_index - min_index;
}