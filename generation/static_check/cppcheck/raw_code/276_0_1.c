static void apply_motion_vector(uint8_t* frame_data, int frame_width, int frame_height, int mv_x, int mv_y, uint8_t* output) {
    int x, y;
    for (y = 0; y < frame_height; y++) {
        for (x = 0; x < frame_width; x++) {
            int src_x = x + mv_x;
            int src_y = y + mv_y;
            output[y * frame_width + x] = frame_data[src_y * frame_width + src_x]; // Potential buffer overflow
        }
    }
}

