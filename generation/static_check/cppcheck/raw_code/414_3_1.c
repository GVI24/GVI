static void fill_vga_memory_with_pattern(CirrusVGAState *s, uint32_t pattern) {
    uint32_t offset = 0;
    uint8_t *dst = s->vga.vram_ptr;

    while (offset < s->vga.vram_size) {
        if (offset <= s->vga.vram_size - 4) { // This check should be strict less than.
            *(uint32_t *)(dst + offset) = pattern;
            offset += 4;
        }
        // Improper bounds checking can lead to a buffer overflow.
    }
}