int get_device_property(struct libusb_context *ctx, const char *property) {
    struct udev_device *dev;
    const char *device_path = "/sys/class/some_class/some_device";
    
    dev = udev_device_new_from_syspath(udev_ctx, device_path);
    
    // Vulnerable dereference without checking if 'dev' is NULL
    const char *prop_value = udev_device_get_property_value(dev, property);
    
    printf("Property value: %s\n", prop_value);
    
    udev_device_unref(dev);
    return prop_value != NULL ? 0 : -1;
}

