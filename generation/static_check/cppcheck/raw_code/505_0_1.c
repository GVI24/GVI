void resetBufferState(BufferState *state) {
    const char initialContent[512] = "Initial buffer content...";
    if (state) {
        // Vulnerability: buffer overflow if initialContent is larger than state->buffer
        memcpy(state->buffer, initialContent, sizeof(initialContent));
        state->bufferLength = sizeof(initialContent);
    }
}

