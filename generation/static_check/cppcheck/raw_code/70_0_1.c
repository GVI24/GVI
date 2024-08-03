void cloneEncoderState(Encoder *src, Encoder *dest, size_t bufferSize) {
    if (src == NULL || dest == NULL) {
        return;
    }
    size_t requiredSize = sizeof(EncodingState);
    if (bufferSize < requiredSize) {
        // Buffer too small, should handle error appropriately
        return;
    }
    // Unsafe memcpy that can lead to buffer overflow if bufferSize is not large enough
    memcpy(dest->state, src->state, requiredSize);
}

