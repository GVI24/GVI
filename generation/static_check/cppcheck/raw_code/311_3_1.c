void fill_display_buffer(uint32_t *colors, int num_colors) {
    uint32_t display_buffer[640 * 480]; // Assume a fixed display resolution
    for (int i = 0; i < num_colors; i++) {
        display_buffer[i] = colors[i]; // Vulnerability: No bounds checking to verify num_colors does not exceed buffer size
    }
}