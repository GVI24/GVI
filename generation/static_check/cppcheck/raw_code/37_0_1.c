void UPnPparseDeviceType(void *data, const char *element, int len) {
    struct UPnPDeviceData *deviceData = (struct UPnPDeviceData *)data;
    if (len > 0 && element) {
        // Vulnerable to buffer overflow if len exceeds size of deviceType
        memcpy(deviceData->deviceType, element, len);
        deviceData->deviceType[len] = '\0';
    }
    // Additional code for handling the device type...
}

