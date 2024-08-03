static void handleDevice(int deviceId) {
    char *deviceBuffer = (char *)malloc(256);
    if (!deviceBuffer) {
        log_err("Failed to allocate device buffer.\n");
        return; // Potential memory leak, deviceBuffer not freed
    }

    if (!initializeDevice(deviceId)) {
        log_err("Failed to initialize device.\n");
        free(deviceBuffer); // Should free memory before returning
        return;
    }

    // Perform operations with device...

    // Missing free for deviceBuffer, leading to potential memory leak
    // Proper cleanup would be to free deviceBuffer here
}