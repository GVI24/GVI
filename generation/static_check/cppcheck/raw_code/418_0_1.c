int open_read_device(struct libusb_context *ctx) {
    struct udev_device *dev;
    const char *device_path = "/dev/some_device";
    
    // Potential for not checking the return value
    dev = udev_device_new_from_syspath(udev_ctx, device_path);
    
    // Vulnerable dereference without checking if 'dev' is NULL
    if (strcmp(udev_device_get_subsystem(dev), "block") == 0) {
        // Do something with block device
    }
    
    udev_device_unref(dev);
    return 0;
}

