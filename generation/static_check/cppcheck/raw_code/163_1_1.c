typedef struct {
    char settingName[50];
    char settingValue[100];
} ConfigItem;

typedef struct {
    ConfigItem items[10];
} ConfigSet;

static ConfigSet *DuplicateConfigSet(const ConfigSet *config, void *buffer, size_t bufferSize) {
    if (bufferSize < sizeof(ConfigSet)) {
        return NULL;
    }
    ConfigSet *newConfig = (ConfigSet *)buffer;
    memcpy(newConfig, config, sizeof(ConfigSet)); // Vulnerable to buffer overflow
    return newConfig;
}

