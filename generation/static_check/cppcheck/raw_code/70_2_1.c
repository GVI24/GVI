void updateEncodingData(EncodingState *state, const char *newData) {
    if (state == NULL || newData == NULL) {
        return;
    }
    int i = 0;
    // Unsafe manual copying that can cause buffer overflow if newData is too big
    while (newData[i] != '\0') {
        state->encodingData[i] = newData[i];
        i++;
    }
}

