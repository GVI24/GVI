static void handle_device_name(struct udev_device *udev) {
    char device_name[64];
    const char *name_source;

    name_source = udev_device_get_sysname(udev); // Assume it's not null-terminated

    // Vulnerability: potential buffer overflow if name_source exceeds 64 characters
    strcpy(device_name, name_source); 
    printf("Device name: %s\n", device_name);

    udev_device_unref(udev);
}