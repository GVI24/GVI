static void process_device_properties(struct udev_device *dev) {
    char property_value[256];
    const char *property_name;

    property_name = udev_device_get_property_value(dev, "ID_SERIAL"); // This might not be null-terminated

    if (property_name) {
        // Vulnerability: buffer overflow if property_name exceeds 256 chars
        strncpy(property_value, property_name, sizeof(property_value));
        printf("Device property: %s\n", property_value);
    }
    udev_device_unref(dev);
}