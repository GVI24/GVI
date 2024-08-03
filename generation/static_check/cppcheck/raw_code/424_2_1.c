#define CONFIG_SIZE 64
typedef struct {
    char device_config[CONFIG_SIZE];
} DeviceConfig;

void set_device_config(DeviceConfig *config, const char *configuration) {
    if (config == NULL || configuration == NULL) {
        return;
    }
    // Vulnerability: No bounds checking on the length of configuration
    strncpy(config->device_config, configuration, sizeof(config->device_config));
    config->device_config[CONFIG_SIZE - 1] = '\0';
}

