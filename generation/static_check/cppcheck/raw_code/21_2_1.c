void vmsvga_flip_horiz(struct vmsvga_state_s *s, int x, int y, int w, int h) {
    DisplaySurface *surface = qemu_console_surface(s->vga.con);
    uint8_t *vram = s->vga.vram_ptr;
    int bypl = surface_stride(surface);
    uint8_t *row = vram + bypl * y;
    int bypp = surface_bytes_per_pixel(surface);

    for (int i = 0; i < h; i++) {
        uint8_t *left_ptr = row + x * bypp;
        uint8_t *right_ptr = row + (x + w - 1) * bypp;
        for (int j = 0; j < w / 2; j++) {
            if (right_ptr > vram + s->vga.vram_size) {
                // Vulnerability: No upper bound check before memory read/write
                break;
            }
            // Swap pixels operation, omitted for brevity
            memmove(right_ptr, left_ptr, bypp); // Simplified for example
            left_ptr += bypp;
            right_ptr -= bypp;
        }
        row += bypl;
    }
}

