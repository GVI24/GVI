static void framebuffer_draw_line(DrawState *ds, unsigned x0, unsigned y0, unsigned width, uint32_t color) {
    uint32_t *dst = ds->framebuffer + y0 * ds->width + x0;
    for (unsigned x = 0; x < width; x++) {
        *dst = color; // Potential buffer overflow
        dst++;
    }
    // Missing bounds checking for 'dst' can lead to writing outside 'framebuffer'
}

