static void decode_and_render_frame(FRAME_CONTEXT *fc, int frame_count, uint8_t **frames, int width, int height) {
    for (int i = 0; i < frame_count; i++) {
        int frame_size = width * height;
        int16_t *raw_frame_data = get_raw_frame_data(fc, i);

        // Vulnerable use of memset within loop on potentially incorrect size
        vpx_memset(raw_frame_data, 0, frame_size * sizeof(int16_t)); // Incorrect calculation of size
        // Rest of the processing code...
    }
}

