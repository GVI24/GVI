#define MAX_CONFIG_SIZE 512
typedef struct {
    char data[MAX_CONFIG_SIZE];
} Configuration;

void setupConfig(Configuration *config, const char *configData) {
    // Copies potentially large input data into a fixed-size buffer
    memcpy(config->data, configData, strlen(configData)); // This does not check if configData is longer than MAX_CONFIG_SIZE.
}

// Usage
Configuration appConfig;
const char *configInput = "Large configuration data block ... (more data)... exceeding the safe limit";
setupConfig(&appConfig, configInput);