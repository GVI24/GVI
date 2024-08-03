static void copy_framebuffer_section(uint8_t *dest_buffer, int dest_pitch, const uint8_t *src_buffer, int src_pitch, int copy_width, int copy_height) {
    int x, y;
    for (y = 0; y < copy_height; y++) {
        for (x = 0; x < copy_width; x++) {
            int dest_index = y * dest_pitch + x;
            int src_index = y * src_pitch + x;
            dest_buffer[dest_index] = src_buffer[src_index]; // Potential out-of-bounds access
        }
    }
}

