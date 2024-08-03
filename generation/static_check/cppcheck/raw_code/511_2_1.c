void decode_frame(uint8_t *frame, int frame_size, uint8_t *coefficients) {
    uint8_t decoded_frame[1024]; // Fixed size buffer
    for (int i = 0; i < frame_size; i++) {
        // No check for frame_size being larger than buffer size
        decoded_frame[i] = frame[i] + coefficients[i % 64];
    }
    // Copy the decoded frame data back
    for (int i = 0; i < frame_size; i++) {
        frame[i] = decoded_frame[i];
    }
}
