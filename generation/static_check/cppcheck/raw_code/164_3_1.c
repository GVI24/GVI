void apply_video_frame_effects(VideoFrame *frame, int num_effects) {
    int i;
    for (i = 0; i <= num_effects; i++) {
        Effect eff = frame->effects[i]; // Potential out-of-bounds access
        // Loop through the pixels to apply effects...
        for (int y = 0; y < frame->height; y++) {
            for (int x = 0; x < frame->width; x++) {
                // Effect application logic
            }
        }
    }
}