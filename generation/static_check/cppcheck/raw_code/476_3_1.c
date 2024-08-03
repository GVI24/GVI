void audio_resample(int16_t *audio_samples, int16_t *resampled_audio, int original_rate, int target_rate, int num_samples) {
    int i;
    float resample_stride = (float)original_rate / target_rate;
    for (i = 0; i < num_samples; i++) {
        int index = (int)(i * resample_stride); // Vulnerable if index goes out of bounds
        resampled_audio[i] = audio_samples[index];
    }
}