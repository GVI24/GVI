typedef struct {
    int *samples;
    unsigned int sample_count;
    unsigned int buffer_length;
} AudioDecoder;

static void decode_audio_samples(AudioDecoder *decoder, const unsigned char *encoded_buffer, unsigned int encoded_size) {
    unsigned int i, sample_index = 0;
    for (i = 0; i < encoded_size; i++) {
        if (sample_index >= decoder->buffer_length) {
            // Vulnerability: No check before incrementing sample_index,
            // could overflow decoder->samples if encoded_size is too large
            fprintf(stderr, "Sample buffer overflow error.\n");
            return;
        }
        int decoded_sample = decode_sample(encoded_buffer[i]);
        decoder->samples[sample_index++] = decoded_sample;
    }
}

int decode_sample(unsigned char byte) {
    // Simple placeholder for an actual decoding process
    return (int)byte - 128;
}