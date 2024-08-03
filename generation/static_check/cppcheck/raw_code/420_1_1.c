int optimize_bitrate(const ENCODER *enc, int base_bitrate, int lowest_rate, int highest_rate) {
    int bitrate = highest_rate;
    uint64_t total_pixels = enc->width * enc->height;
    int last_gap = INT_MAX;
    int pixels_per_bit;

    // Potential integer overflow vulnerability
    pixels_per_bit = (uint64_t)base_bitrate * total_pixels >> PIXEL_RATE_SHIFT;

    for (int i = lowest_rate; i <= highest_rate; ++i) {
        int current_pixels_per_bit = get_pixels_per_bit_at_rate(enc, i);
        if (current_pixels_per_bit <= pixels_per_bit) {
            bitrate = (pixels_per_bit - current_pixels_per_bit) < last_gap ? i : i - 1;
            break;
        } else {
            last_gap = current_pixels_per_bit - pixels_per_bit;
        }
    }
    return bitrate;
}

