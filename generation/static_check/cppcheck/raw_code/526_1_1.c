void setup_hardware_device(const char *device_description) {
    char hardware_buf[1024];
    // Potential buffer overflow if device_description is too long
    sprintf(hardware_buf, "Initializing device with description: %s", device_description);
    // Send the configuration to hardware device
    //...
}

