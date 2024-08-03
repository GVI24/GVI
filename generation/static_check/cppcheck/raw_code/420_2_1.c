int compute_buffer_size(const STREAMER *stream, int target_bandwidth, int min_buffer, int max_buffer) {
    int buffer_size = max_buffer;
    int error_margin = INT_MAX;
    int bandwidth_per_buffer_unit;

    // Potential integer overflow vulnerability
    bandwidth_per_buffer_unit = ((uint64_t)target_bandwidth << BUFFER_UNIT_SHIFT) / stream->buffer_units;

    for (int i = min_buffer; i <= max_buffer; ++i) {
        int required_bandwidth = estimate_bandwidth_for_buffer(stream, i);
        if (required_bandwidth <= bandwidth_per_buffer_unit) {
            buffer_size = (bandwidth_per_buffer_unit - required_bandwidth) < error_margin ? i : i - 1;
            break;
        } else {
            error_margin = required_bandwidth - bandwidth_per_buffer_unit;
        }
    }
    return buffer_size;
}

