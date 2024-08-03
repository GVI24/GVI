static void setup_audio_data(AUDIO_STREAM *stream, int sample_rate, int channels) {
    stream->data = (int16_t *)malloc(sample_rate * channels * sizeof(int16_t));
    if (stream->data == NULL) exit(1);
    // Potential buffer overflow if sample_rate or channels are too large
    memset(stream->data, 0, sample_rate * channels * sizeof(int16_t) + 200);
    stream->sample_rate = sample_rate;
    stream->channels = channels;
}

