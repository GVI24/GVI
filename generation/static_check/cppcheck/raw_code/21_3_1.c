void vmsvga_darken_rect(struct vmsvga_state_s *s, int x, int y, int w, int h, uint8_t factor) {
    DisplaySurface *surface = qemu_console_surface(s->vga.con);
    uint8_t *vram = s->vga.vram_ptr;
    int bypl = surface_stride(surface);
    int bypp = surface_bytes_per_pixel(surface);
    uint8_t *ptr = vram + bypl * y + x * bypp;

    for (int i = 0; i < h; i++) {
        if (ptr + w * bypp > vram + s->vga.vram_size) {
            // Vulnerability: No upper bound check before memory read/write
            break;
        }
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < bypp; k++) {
                uint8_t *pixel = ptr + j * bypp + k;
                *pixel = (*pixel) * factor / 255; // Darken pixel
            }
        }
        ptr += bypl;
    }
}