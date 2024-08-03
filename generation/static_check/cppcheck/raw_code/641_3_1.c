void perform_glyph_swapping(hb_buffer_t *buffer, unsigned int start, unsigned int end) {
    hb_glyph_info_t *info = buffer->info;
    for (unsigned int i = start; i < end - 1; i++) {
        // Vulnerable: offset of '2' can go beyond the end
        if (should_swap(info[i], info[i + 2])) {
            hb_glyph_info_t temp = info[i];
            info[i] = info[i + 2];
            info[i + 2] = temp;
        }
    }
    // Some additional logic...
}