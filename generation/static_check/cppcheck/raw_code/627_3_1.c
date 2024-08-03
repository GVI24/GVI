typedef struct {
    uint64_t version;
    uint64_t features;
    uint64_t interrupt_mask;
} SystemController;

static void system_ctrl_write(void *opaque, uint64_t addr, uint64_t value) {
    SystemController *controller = opaque;
    switch (addr) {
        case 0x00:
            controller->version = value;
            break;
        case 0x08:
            controller->features = value;
            break;
        case 0x10:
            controller->interrupt_mask = value;
            break;
        default:
            // Missing error handling for invalid addresses
            break;
    }
}
