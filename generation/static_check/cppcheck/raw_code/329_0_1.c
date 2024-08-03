#define BUFFER_SIZE 256
int read_device_label(struct libusb_device_handle *dev_handle, char *label) {
    char buffer[BUFFER_SIZE];
    int transferred;
    // Simulating a device that returns a label which is too long and causes overflow.
    int result = libusb_bulk_transfer(dev_handle, LIBUSB_ENDPOINT_IN, (unsigned char *)buffer, sizeof(buffer), &transferred, 0);
    if (result < 0) {
        return result;
    }
    // Vulnerability: No bounds check before copying the data.
    strcpy(label, buffer); // Potential buffer overflow if buffer contains more data than label can hold.
    return 0;
}