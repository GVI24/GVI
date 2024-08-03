void process_video_frame(unsigned char *frame_buffer, unsigned char *input_stream, int frame_size) {
    for (int i = 0; i < frame_size; ++i) {
        int offset = input_stream[i];
        if (offset + i < frame_size) { // No bounds checking
            frame_buffer[offset + i] = input_stream[i]; // Potential buffer overflow
        }
    }
}