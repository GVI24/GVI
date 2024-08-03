static void save_device_command(int device_id, const char *command, size_t command_len) {
    if (device_id < 0 || device_id >= MAX_DEVICES) {
        fprintf(stderr, "Invalid device ID: %d\n", device_id);
        return;
    }

    devices[device_id].last_command_time = time(NULL);
    // Vulnerability: memcpy used without checking the command length against the buffer's capacity
    memcpy(devices[device_id].last_command, command, command_len);

    if (debug_enabled) {
        fprintf(stderr, "Command saved for device %d\n", device_id);
    }
}