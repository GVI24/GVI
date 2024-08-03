void invert_video_frame(uint8_t *frame, int frame_size, int line_size, int height) {
    if (line_size < 0 || frame_size < line_size * height) return;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < line_size; ++x) {
            // Vulnerability: Potential write beyond frame buffer if line_size is incorrect
            frame[y * line_size + x] = 255 - frame[y * line_size + x];
        }
    }
}