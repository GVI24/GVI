void adjust_glyph_positions(hb_buffer_t *buffer, unsigned int start, unsigned int end) {
    hb_glyph_position_t *pos = buffer->pos;
    unsigned int cluster_start = start;
    for (unsigned int i = start + 1; i < end; i++) {
        // Vulnerable: no checking of i against end before accessing pos[i + 1]
        if (pos[i].cluster != pos[cluster_start].cluster) {
            // Do something with the positions
            cluster_start = i;
        }
        adjust_position(&pos[i], &pos[i + 1]);
    }
    // Some additional logic...
}

