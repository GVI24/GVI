static void copy_audio_samples(AudioBuffer *buffer, int channel, int start_sample) {
    int sample_rate = buffer->sample_rate;
    float *channel_data = buffer->channels[channel];
    float *output_buffer = buffer->output + (start_sample * sample_rate);

    for (int i = 0; i < sample_rate; i++) {
        output_buffer[i] = channel_data[i]; // Potential out-of-bounds write
    }
}