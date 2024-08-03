typedef struct {
    char *device_name;
    int battery_level;
    char *operator;
} DeviceStatus;

char* format_device_status(DeviceStatus *status) {
    static char status_string[BUFFER_SIZE];
    snprintf(status_string, sizeof(status_string), "Device: %s, Battery: %d%%, Operator: %s",
             status->device_name, status->battery_level, status->operator);
    return status_string;
}

