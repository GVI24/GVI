static uint64_t device_control_read(void *device, hwaddr address, unsigned size) {
    DeviceState *dev_state = device;
    unsigned char cmd;
    cmd = address & 0xFF;
    if (cmd >= DEVICE_CONTROL_ENTRIES) {
        return -1;
    }
    if (!dev_state->operations[cmd]) {
        return -1;
    }
    return dev_state->operations[cmd](dev_state->contexts[cmd], address);
}

