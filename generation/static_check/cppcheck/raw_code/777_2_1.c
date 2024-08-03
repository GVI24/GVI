void process_video_frame(uint8_t **frame_buffers, int num_buffers, int current_index) {
    if (current_index < 0 || current_index >= num_buffers) {
        // Handle invalid index error
        return;
    }
    // Process the current frame
    // ...
    // Free the current frame after processing
    free(frame_buffers[current_index]); // Use-after-free: frame_buffers[current_index] should not be accessed after this point
    // ...
    // Incorrectly use the freed buffer
    memset(frame_buffers[current_index], 0, WIDTH * HEIGHT); // Using the freed buffer, leads to undefined behavior
}

