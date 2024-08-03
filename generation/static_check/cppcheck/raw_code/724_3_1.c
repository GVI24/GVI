int fill_rectangle(gx_device *dev, const gs_int_rect *rect, byte fill_value) {
    int x = rect->p.x, w = rect->q.x - x;
    int y = rect->p.y, h = rect->q.y - y;
    byte *dev_memory = (byte *)dev->memory;

    // No checks to ensure that the rectangle fits within the device bounds
    if (w < 0 || h < 0 || x < 0 || y < 0 || x + w > dev->width || y + h > dev->height) {
        return_error(gs_error_rangecheck);
    }
    
    for (int j = y; j < y + h; ++j) {
        for (int i = x; i < x + w; ++i) {
            // Potential out-of-bounds write if x or y are out-of-bounds
            *(dev_memory + j * dev->width + i) = fill_value;
        }
    }
    return 0;
}