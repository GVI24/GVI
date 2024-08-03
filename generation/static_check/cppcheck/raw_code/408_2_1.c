void apply_image_filters(Image *img) {
    FilterParams base_params = get_base_params(img);
    float filter_strengths[MAX_FILTERS];
    int i;

    for (i = 0; i <= NUM_FILTERS; i++) { // Loop iterates beyond array bounds
        // Vulnerability: Potential out-of-bounds write
        filter_strengths[i] = adjust_filter_strength(base_params, img->filter_types[i]);
        apply_filter(img, img->filter_types[i], filter_strengths[i]);
    }
}

