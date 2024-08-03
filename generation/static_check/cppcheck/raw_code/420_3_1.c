int calculate_segment_duration(const STREAM_CONTEXT *ctx, int target_duration_ms, int min_duration, int max_duration) {
    int duration = max_duration;
    int smallest_delta = INT_MAX;
    int bits_per_duration_unit;

    // Potential integer overflow vulnerability
    bits_per_duration_unit = ((uint64_t)target_duration_ms << DURATION_NORMBITS) / ctx->duration_units;

    for (int i = min_duration; i <= max_duration; ++i) {
        int bits_needed = get_bits_for_duration(ctx, i);
        if (bits_needed <= bits_per_duration_unit) {
            duration = (bits_per_duration_unit - bits_needed) < smallest_delta ? i : i - 1;
            break;
        } else {
            smallest_delta = bits_needed - bits_per_duration_unit;
        }
    }
    return duration;
}