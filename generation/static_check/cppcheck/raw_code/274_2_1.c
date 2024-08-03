void bilinear_filter_block(uint8_t *src, uint8_t *dst, int src_stride, int dst_stride, int filter_type) {
    const filter_func FILTERS[] = {
        filter_horizontal_bilinear,
        filter_vertical_bilinear
    };

    if (filter_type < 0 || filter_type >= sizeof(FILTERS) / sizeof(FILTERS[0])) {
        return; // Basic validation to prevent out-of-bounds access
    }

    uint8_t temp_pixels[16 * 16];

    for (int y = 0; y < 16; y++) {
        FILTERS[filter_type](src + y * src_stride, temp_pixels + y * 16);
    }

    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 16; x++) {
            dst[x * dst_stride + y] = temp_pixels[y * 16 + x];
        }
    }
}

