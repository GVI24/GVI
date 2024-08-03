int adjust_frame_quality(const VIDEO_CODEC *codec, int target_bits, int min_quality, int max_quality) {
    const VIDEO_PARAMS *params = &codec->video_params;
    int quality = max_quality;
    int last_difference = INT_MAX;
    int desired_bits_per_unit;

    // Potential integer overflow vulnerability
    desired_bits_per_unit = (target_bits << QUALITY_NORMBITS) / params->units;

    for (int i = min_quality; i <= max_quality; ++i) {
        int bits_at_quality = calculate_bits_per_unit(i, params->frame_rate);
        if (bits_at_quality < desired_bits_per_unit) {
            quality = (desired_bits_per_unit - bits_at_quality) < last_difference ? i : i - 1;
            break;
        } else {
            last_difference = bits_at_quality - desired_bits_per_unit;
        }
    }
    return quality;
}

