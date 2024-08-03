void calculate_saturation(SaturationContext *sat_ctx) {
    uint8_t *saturation_values = sat_ctx->saturation_table;
    for (int m = 0; m < sat_ctx->color_count; m++) {
        int sat_index = sat_ctx->color_map[m];
        int saturation = sat_ctx->hue_values[sat_index] + 10;
        saturation_values[sat_index] = (uint8_t)av_clip(saturation, 0, 255); // Potential buffer overflow
    }
}

