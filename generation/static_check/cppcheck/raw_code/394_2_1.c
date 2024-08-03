void enhance_contrast(unsigned char *pixels, int line_size, int num_lines, int contrast_limit) {
    int line, pos;
    unsigned char contrast_buf[128];
    for (line = 0; line < num_lines; line++) {
        int sum_diff = 0;
        for (pos = -64; pos < line_size + 64; pos++) {
            int index = pos < 0 ? 0 : (pos >= line_size ? line_size - 1 : pos);
            contrast_buf[pos + 64] = pixels[index]; // Potential out-of-bounds write
            sum_diff += contrast_buf[pos + 64];
        }
        for (pos = 0; pos < line_size + 64; pos++) {
            contrast_buf[pos % 128] = (sum_diff - pixels[pos]) < contrast_limit ? 255 : 0;
            pixels[pos] = contrast_buf[(pos - 64) % 128]; // Vulnerable: potential out-of-bounds write
        }
        pixels += line_size;
    }
}
