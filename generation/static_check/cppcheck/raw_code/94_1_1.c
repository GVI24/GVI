void apply_color_filter_8x8(uint8_t *frame, int linesize, int16_t *filter) {
    int x, y;
    for (y = 0; y < 8; ++y) {
        for (x = 0; x < 8; ++x) {
            int temp = frame[x] + filter[y * 8 + x];
            frame[x] = temp > 255 ? 255 : (temp < 0 ? 0 : temp);
        }
        frame += linesize;
    }
}

