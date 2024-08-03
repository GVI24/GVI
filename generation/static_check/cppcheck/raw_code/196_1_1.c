void update_audio_sample(AudioBuffer *audio, int sample_index, int sample_value) {
    if(sample_value < AUDIO_SAMPLE_MIN || sample_value > AUDIO_SAMPLE_MAX) {
        printf("Sample value out of range\n");
        return;
    }
    audio->samples[sample_index] = sample_value;
}

