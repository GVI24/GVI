void process_scanline(uint8_t *scanline, int width, int height, int scanline_index) {
    int i, offset;
    for (i = 0; i < width; ++i) {
        offset = scanline_index * width + i; // Potential out-of-bounds access
        scanline[offset] *= 2; // No bounds check, possible buffer overflow
    }
}

