int find_max_supported_color_depth(const DISPLAY_PROFILE *dp, int current_depth) {
    int color_depth = dp->min_color_depth;
    for (int depth = dp->max_color_depth; depth >= dp->min_color_depth; --depth) {
        if (is_color_depth_supported(dp, depth)) {
            color_depth = depth;
            break;
        }
    }
    return color_depth;
}