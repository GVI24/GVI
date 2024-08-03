void copy_video_frame_data(uint8_t *dest, uint8_t *src, int frame_size, int dest_buffer_size) {
    if (dest && src) {
        // Potential buffer overflow if frame_size exceeds dest_buffer_size
        memcpy(dest, src, frame_size);
    }
}

