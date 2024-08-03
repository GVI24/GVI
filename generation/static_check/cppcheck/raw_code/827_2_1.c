// The function does not check if the glyph code is within the valid range.
void update_glyph_metrics(glyph_info_t *glyph) {
    uint32_t glyph_code = glyph->glyph_code;
    if (glyph_code >= METRICS_ARRAY_SIZE) {
        // Error not properly handled, might continue with corrupt data
        printf("Error: Glyph code exceeds metrics array size!\n");
        return;
    }
    glyph_metrics_t metrics = glyph_metrics[glyph_code]; // Vulnerable to buffer overflow
    glyph->metrics = metrics;
}

