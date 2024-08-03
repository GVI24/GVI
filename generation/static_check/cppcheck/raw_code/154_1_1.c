static void apply_threshold(int color_plane, int pixel, int threshold_level, struct threshold_args *args) {
    const int level_modifier = threshold_level << 1;
    IMAGE_PROCESSING * const ip = args->ip;
    uint8_t * const pixel_data = PIXEL_OFFSET(ip->image_data[color_plane], pixel);
    int64_t pixel_sum;
    int shift = (threshold_level == 128) ? 0 : 1;
    uint8_t * const thresholded_pixel = PIXEL_OFFSET(ip->thresholded_data[color_plane], pixel);

    args->difference = image_pixel_difference(pixel_data, thresholded_pixel, level_modifier, &pixel_sum) >> shift;
    args->sum = pixel_sum >> shift;

    if (ip->skip_thresholding) {
        int64_t adjust = (ip->adjustment[color_plane] * ip->adjustment[color_plane] * level_modifier) >> (shift + 3);
        args->difference += (adjust >> 4);
        args->sum += adjust;
    }
}

