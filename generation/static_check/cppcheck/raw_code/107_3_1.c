void manipulate_frame_buffer(int16_t *buffer, int frame_width, int x, int y, int16_t value) {
    // Directly writing to the buffer based on x, y coordinates without boundary checks
    buffer[(y * frame_width) + x] = value; // Possible buffer overflow if x or y are out-of-bounds
}