void decode_stream(const uint8_t *encoded, size_t length, uint8_t *decoded) {
    size_t decoded_index = 0;
    for (size_t i = 0; i < length; i++) {
        if (encoded[i] == 0xFF) {
            if (i + 1 < length && encoded[i + 1] == 0x00) {
                decoded[decoded_index++] = encoded[i++]; // Potentially incrementing 'i' beyond 'length'
            } else {
                // Error handling omitted for brevity
            }
        } else {
            decoded[decoded_index++] = encoded[i];
        }
    }
    // No null-termination or buffer size check for 'decoded' array
}