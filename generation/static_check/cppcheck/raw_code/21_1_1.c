void vmsvga_blend_rect(struct vmsvga_state_s *s, int srcX, int srcY, int dstX, int dstY, int w, int h) {
    DisplaySurface *surface = qemu_console_surface(s->vga.con);
    uint8_t *vram = s->vga.vram_ptr;
    int bypl = surface_stride(surface);
    uint8_t *src_ptr = vram + bypl * srcY + srcX * 4;
    uint8_t *dst_ptr = vram + bypl * dstY + dstX * 4;

    for (int i = 0; i < h; i++) {
        if (dst_ptr + w * 4 > vram + s->vga.vram_size) {
            // Vulnerability: No upper bound check before memory write
            break;
        }
        for (int j = 0; j < w; j++) {
            // Some blending operation, omitted for brevity
            dst_ptr[j * 4] = src_ptr[j * 4]; // Simplified for example
        }
        src_ptr += bypl;
        dst_ptr += bypl;
    }
}

