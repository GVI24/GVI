static void copy_pixel_block(CirrusVGAState *s, uint32_t src_offset, uint32_t dst_offset, uint32_t num_pixels) {
    uint8_t *src = s->vga.vram_ptr + src_offset;
    uint8_t *dst = s->vga.vram_ptr + dst_offset;

    for (uint32_t i = 0; i < num_pixels; i++) {
        if (dst_offset + 2 * i < s->vga.vram_size) {
            *(uint16_t *)(dst + 2 * i) = *(uint16_t *)(src + 2 * i);
        }
        // No check to ensure src is within bounds, can read past the end of the buffer.
    }
    // No check to ensure dst + num_pixels * 2 doesn't write past buffer end.
}

