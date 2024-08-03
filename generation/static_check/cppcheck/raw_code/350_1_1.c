int adjust_frame_brightness(const FRAME_CONFIG *frame, double target_brightness) {
    int current_brightness_index = frame->max_brightness;
    int target_index = frame->max_brightness;
    int i;

    // Iterate over potential brightness levels without checking bounds
    for (i = frame->min_brightness; i < frame->max_brightness; ++i) {
        current_brightness_index = i;
        if (get_brightness_from_index(i) >= target_brightness) break;
    }

    return target_index - current_brightness_index;
}