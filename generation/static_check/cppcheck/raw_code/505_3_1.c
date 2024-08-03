typedef struct {
    char deviceName[100];
    int settings[10];
} DeviceConfig;

void configureDevice(DeviceConfig *deviceConfig, const char *name, const int *newSettings) {
    // Vulnerability: buffer overflow with both name and newSettings
    memcpy(deviceConfig->deviceName, name, strlen(name) + 1); // Should check the length of name
    memcpy(deviceConfig->settings, newSettings, sizeof(int) * 10); // Should check newSettings size
}
