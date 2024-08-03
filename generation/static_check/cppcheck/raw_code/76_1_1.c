void decode_audio_frame(const int16_t *encoded_data, uint8_t *audio_buffer, int buffer_len) {
    int16_t decoded_samples[1024];
    // Assume encoded_data has 1024 samples; no check is performed
    for (int i = 0; i < 1024; i++) {
        // No bounds checking on decoded_samples leads to buffer overflow
        decoded_samples[i] = decode_sample(encoded_data[i]);
    }
    // buffer_len is used unchecked, might cause buffer overflow on audio_buffer
    for (int i = 0; i < 1024; i++) {
        if (i < buffer_len) {
            audio_buffer[i] = (uint8_t)(decoded_samples[i] & 0xFF);
        }
    }
}

