typedef struct {
    uint64_t control_register;
    uint64_t status_register;
    uint64_t config_fields[MAX_DEVICES];
} DeviceController;

static void controller_write(void *opaque, uint64_t addr, uint64_t value) {
    DeviceController *controller = opaque;
    if (addr >= 0x100 && addr <= 0x100 + (MAX_DEVICES - 1) * sizeof(uint64_t)) {
        // Writing to device configuration fields
        int index = (addr - 0x100) / sizeof(uint64_t);
        controller->config_fields[index] = value;
    } else if (addr == 0x0) {
        // Writing to control register
        controller->control_register = value;
    } else {
        // Fallback for unknown addresses
        // Missing error handling for Out-of-Bounds addresses
    }
}
