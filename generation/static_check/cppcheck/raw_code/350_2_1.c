int select_audio_sample_rate(const AUDIO_CONFIG *audio_config, double desired_quality) {
    int min_quality_index = audio_config->max_quality_index;
    int target_quality_index = audio_config->max_quality_index;
    int i;

    // Loop to find sample rate index, without bounds checks
    for (i = audio_config->min_quality_index; i < audio_config->max_quality_index; ++i) {
        min_quality_index = i;
        if (convert_quality_to_samplerate(i) >= desired_quality) break;
    }

    return target_quality_index - min_quality_index;
}