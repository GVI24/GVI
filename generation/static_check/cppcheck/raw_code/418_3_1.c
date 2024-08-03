int enumerate_device_attributes(struct libusb_context *ctx) {
    struct udev_device *dev;
    struct udev_list_entry *attributes, *entry;
    
    const char *syspath = "/sys/devices/pci0000:00/";
    dev = udev_device_new_from_syspath(udev_ctx, syspath);
    
    // Vulnerable dereference without checking if 'dev' is NULL
    attributes = udev_device_get_sysattr_list_entry(dev);
    udev_list_entry_foreach(entry, attributes) {
        const char *name = udev_list_entry_get_name(entry);
        const char *value = udev_device_get_sysattr_value(dev, name);
        
        printf("Attribute %s: %s\n", name, value);
    }
    
    udev_device_unref(dev);
    return 0;
}