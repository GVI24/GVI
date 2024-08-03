
static int resize_image_buffer(uint8_t *src, int src_width, int src_height, uint8_t *dst, int dst_width, int dst_size) {
    int x_ratio = (int)((src_width << 16) / dst_width) + 1;
    int y, x;

    for (y = 0; y < src_height; y++) {
        for (x = 0; x < dst_width; x++) {
            int src_x = (x * x_ratio) >> 16;
            dst[(y * dst_width) + x] = src[(y * src_width) + src_x]; // Potential buffer overflow if 'dst' is too small
        }
    }

    return dst_size; // Return value could be misleading if overflow happens
}

