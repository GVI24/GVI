static void update_device_status(struct udev_device *dev) {
    const char *status;
    char status_msg[100];

    status = udev_device_get_sysattr_value(dev, "status"); // Assume this could return a long string

    if (status) {
        // Vulnerability: buffer overflow if status is longer than 100 characters
        snprintf(status_msg, sizeof(status_msg), "Device Status: %s", status);
        printf("%s\n", status_msg);
    }
    udev_device_unref(dev);
}