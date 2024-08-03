static void log_device_event(struct udev_device *device) {
    char buffer[128];
    const char *action;
    const char *dev_path;

    action = udev_device_get_action(device);
    dev_path = udev_device_get_devpath(device); // Assume this isn't null-terminated

    if (action && dev_path) {
        // Vulnerability: buffer overflow if dev_path is too long
        snprintf(buffer, sizeof(buffer), "Action: %s, Path: %s", action, dev_path); 
        puts(buffer);
    }
    udev_device_unref(device);
}