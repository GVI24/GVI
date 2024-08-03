void decode_audio_samples(short *audio_buffer, const short *encoded_data, int buffer_size, int num_samples) {
    int sample_index = 0;
    while (num_samples--) {
        int jump = *encoded_data++; // No validation on the contents of encoded_data
        sample_index += jump; // No bounds checking
        if (sample_index < buffer_size) {
            audio_buffer[sample_index] = *encoded_data++; // Potential buffer overflow
        }
    }
}