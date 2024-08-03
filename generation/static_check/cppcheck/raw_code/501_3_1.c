typedef enum {
    MODE_A,
    MODE_B,
    MODE_C,
    MODE_TYPE_COUNT // Should not be used as a mode
} ModeType;

typedef struct {
    int mode_config[MODE_TYPE_COUNT];
} Device;

int get_mode_config(Device *device, ModeType type) {
    // Vulnerability: MODE_TYPE_COUNT or out-of-range value can be passed as 'type'
    return device->mode_config[type]; // Potential out-of-bounds read
}
