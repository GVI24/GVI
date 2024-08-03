static void update_firmware(char *data, int data_len, struct device *dev) {
    if (authenticate_device(dev->serial) != 0) {
        return;
    }
    dev->last_update_time = time(NULL);
    memcpy(dev->firmware_image, data, data_len); // Potential buffer overflow
    if (debug) {
        fprintf(stderr, "Firmware update with size %d for device %s\n", data_len, dev->serial);
    }
    flash_firmware(dev);
}

