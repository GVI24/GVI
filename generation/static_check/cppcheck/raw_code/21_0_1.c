void vmsvga_fill_rect(struct vmsvga_state_s *s, int x, int y, int w, int h, uint32_t color) {
    DisplaySurface *surface = qemu_console_surface(s->vga.con);
    uint8_t *vram = s->vga.vram_ptr;
    int bypl = surface_stride(surface);
    uint8_t *ptr = vram + bypl * y + x * sizeof(color);

    for (int i = 0; i < h; i++) {
        if (ptr + w * sizeof(color) > vram + s->vga.vram_size) {
            // Vulnerability: No upper bound check before memory write
            break;
        }
        for (int j = 0; j < w; j++) {
            *(uint32_t *)(ptr + j * sizeof(color)) = color;
        }
        ptr += bypl;
    }
}

