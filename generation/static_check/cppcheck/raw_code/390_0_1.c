static inline void simple_blit_image(struct simple_state_s *s, uint32_t color, int x, int y, int w, int h) {
    uint8_t *framebuffer = s->framebuffer;
    int pitch = s->pitch;
    uint8_t color_bytes[3]; // Assuming a 24-bit color depth framebuffer
    color_bytes[0] = color;
    color_bytes[1] = color >> 8;
    color_bytes[2] = color >> 16;

    // Incorrect bounds checking here could lead to buffer overflow
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w * 3; j++) {
            framebuffer[(y + i) * pitch + x * 3 + j] = color_bytes[j % 3];
        }
    }
}

