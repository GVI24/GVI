static void interpolate_frame(FrameContext *fc, int frame_num, int delta) {
    int frame_index = frame_num % fc->buffer_size;
    int prev_frame_index = (frame_num - 1) % fc->buffer_size;
    int next_frame_index = (frame_num + 1) % fc->buffer_size;
    long interpolation_factor = fc->interpolation_factor;
    int i;

    for (i = 0; i < fc->frame_size; i++) {
        long prev_value = fc->buffer[prev_frame_index][i];
        long next_value = fc->buffer[next_frame_index][i];
        long interpolated_value = prev_value + (next_value - prev_value) * delta / interpolation_factor;
        if (interpolated_value < prev_value || interpolated_value > next_value) { // Overflow check
            // Handle overflow
        }
        fc->buffer[frame_index][i] = interpolated_value;
    }
}

