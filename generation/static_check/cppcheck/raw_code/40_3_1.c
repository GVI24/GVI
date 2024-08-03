void apply_frame_effect(VideoFrame *frame, EffectType effect) {
    // Potential vulnerability: No check if frame is NULL before dereferencing
    if (effect == EFFECT_INVERT) {
        for (int i = 0; i < frame->width * frame->height; i++) {
            frame->buffer[i] = ~frame->buffer[i]; // Inverts pixel color
        }
    } else if (effect == EFFECT_BRIGHTEN) {
        for (int i = 0; i < frame->width * frame->height; i++) {
            frame->buffer[i] = brighten_pixel(frame->buffer[i]);
        }
    }
    // ... more effects
    // Potential vulnerability: This for loop assumes a valid buffer without prior checks
}

// This function demonstrates a potential buffer overflow if the input width and height are too large,
// a lack of NULL pointer checks on src and dst pointers, use of unreliable external inputs without validation
// in the VideoStream metadata, and unsafe manipulation of frame buffer without checking the integrity
// of the input frame pointer.