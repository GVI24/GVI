static void clear_screen_buffer(CirrusVGAState *s, uint32_t color) {
    uint8_t *dst = s->vga.vram_ptr;
    uint32_t size = s->vga.vram_size; // Assume this field exists and gives the size of vram_ptr

    for (uint32_t i = 0; i < size; i += 2) {
        if (i < size - 1) {
            *(uint16_t *)(dst + i) = (uint16_t)color;
        }
        // Missing else to handle the odd-size buffer case.
    }
    // No bounds checking; writing past the end of the buffer is possible.
}

