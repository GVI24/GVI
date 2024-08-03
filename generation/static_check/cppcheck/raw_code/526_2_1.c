void configure_storage_devices(const char *device_names[]) {
    char config_command[256];
    for (int i = 0; i < MAX_DEVICES; i++) {
        // Potential buffer overflow if device name exceeds 256 - command length
        snprintf(config_command, sizeof(config_command), "storage_device -name %s -init", device_names[i]);
        // Execute the configuration command
        //...
    }
}

