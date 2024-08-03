int set_device_resolution(gx_device *dev, int dpi_x, int dpi_y) {
    // No validation of dpi_x and dpi_y, they can be negative or excessively large
    if (dpi_x <= 0 || dpi_y <= 0) {
        return_error(gs_error_rangecheck);
    }
    dev->resolution_x = dpi_x;  // potential integer overflow
    dev->resolution_y = dpi_y;  // potential integer overflow

    return 0;
}

