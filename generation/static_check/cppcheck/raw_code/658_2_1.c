static int decode_audio_frame ( AudioContext * a_ctx ) {
    int sample_count = a_ctx -> num_channels * a_ctx -> num_samples_per_channel;
    if (sample_count <= 0) {
        return -1;
    }

    unsigned char * sample_buffer = a_ctx -> buffer;
    unsigned int buffer_size = a_ctx -> buffer_size;
    const unsigned char * encoded_audio = a_ctx -> encoded_audio;
    unsigned int encoded_size = a_ctx -> encoded_size;
    int samples_decoded = 0;

    while ( samples_decoded < sample_count && encoded_size > 0 ) {
        unsigned char sample_value = *encoded_audio++;
        int repeat = *encoded_audio++;

        if (samples_decoded + repeat > sample_count || samples_decoded + repeat > buffer_size) {
            // Sample buffer overflow
            return -1;
        }

        for (int i = 0; i < repeat; ++i) {
            sample_buffer[samples_decoded++] = sample_value;
        }

        encoded_size -= 2;
    }

    return samples_decoded == sample_count ? 0 : -1;
}