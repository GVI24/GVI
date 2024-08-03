int process_usb_devices(struct libusb_context *ctx) {
    struct udev_enumerate *enumerator;
    struct udev_list_entry *devices, *entry;
    struct udev_device *dev;
    
    enumerator = udev_enumerate_new(udev_ctx);
    udev_enumerate_add_match_subsystem(enumerator, "usb");
    udev_enumerate_scan_devices(enumerator);
    devices = udev_enumerate_get_list_entry(enumerator);
    
    udev_list_entry_foreach(entry, devices) {
        const char *path = udev_list_entry_get_name(entry);
        dev = udev_device_new_from_syspath(udev_ctx, path);
        
        // Vulnerable dereference without checking if 'dev' is NULL
        const char *dev_node = udev_device_get_devnode(dev);
        if (dev_node) {
            printf("Device node: %s\n", dev_node);
        }
        
        udev_device_unref(dev);
    }
    
    udev_enumerate_unref(enumerator);
    return 0;
}

