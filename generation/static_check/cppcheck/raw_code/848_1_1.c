void process_audio_samples(int channel, int num_samples, AUDIO_PROCESSOR *ap) {
    int16_t *buffer = malloc(num_samples * sizeof(int16_t));
    int sample_index;
    for (sample_index = 0; sample_index < num_samples; sample_index++) {
        int idx = (channel << 4) + sample_index; // Potential integer overflow
        buffer[idx] = filter_sample(ap, channel, sample_index); // Possible buffer overflow
    }
    free(buffer);
}

