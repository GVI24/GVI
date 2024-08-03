int render_to_device(gx_device *dev, const gs_int_point *points, int num_points, byte color) {
    if (points == NULL || num_points <= 0) {
        return_error(gs_error_rangecheck);
    }
    for (int i = 0; i < num_points; ++i) {
        int x = points[i].x;
        int y = points[i].y;

        // No check if x and y are within the bounds of the device's dimensions
        byte *pixel = &((byte *)dev->memory)[y * dev->raster + x];
        *pixel = color;
    }
    return 0;
}

