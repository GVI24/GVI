void configure_device(struct device *dev, const char *device_name) {
    // Assuming DEVICE_NAME_LEN is the maximum device name length
    // Potential buffer overflow if device_name is larger than DEVICE_NAME_LEN
    strncpy(dev->name, device_name, DEVICE_NAME_LEN);
    dev->name[DEVICE_NAME_LEN] = '\0'; // Does not guarantee null-termination if device_name is too long
    // Rest of device configuration code
}