int set_device_name(struct libusb_device_handle *dev_handle, const char *device_name) {
    if (dev_handle == NULL) {
        return -1;
    }

    // Vulnerability: There's no check on the length or content of device_name.
    char command[128];
    sprintf(command, "SET_NAME %s", device_name); // Potential overflow and injection if device_name is too long or crafted maliciously.

    // Send the command to the device.
    int transferred;
    libusb_bulk_transfer(dev_handle, LIBUSB_ENDPOINT_OUT, (unsigned char *)command, strlen(command), &transferred, 0);

    return 0;
}