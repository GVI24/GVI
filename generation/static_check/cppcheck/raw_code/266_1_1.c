// from a settings array without proper bounds checking.
static char *getSettingByKey(const SettingsArray *settings, const char *key) {
    for (size_t i = 0; i < settings->count; i++) {
        if (strcmp(settings->keys[i], key) == 0) {
            return settings->values[i];
        }
    }
    // Setting not found. Incorrectly returning a value from uninitialized memory.
    return settings->values[settings->count];
}

