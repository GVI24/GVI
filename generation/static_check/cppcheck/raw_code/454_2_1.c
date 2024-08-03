int determine_encoding_resolution(const ENCODING_PROFILE *ep, int initial_quality) {
    int resolution_index = ep->lowest_resolution;
    for (int i = ep->highest_resolution; i >= ep->lowest_resolution; --i) {
        if (is_resolution_supported(ep, i) && meets_quality_standard(initial_quality, i)) {
            resolution_index = i;
            break;
        }
    }
    return resolution_index;
}

