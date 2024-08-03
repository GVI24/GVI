typedef struct {
    uint64_t clock_rate;
    uint64_t power_state;
} ClockController;

static void clock_write(void *opaque, uint64_t addr, uint64_t value) {
    ClockController *controller = opaque;
    if (addr == 0x0) {
        controller->clock_rate = value;
    } else if (addr == 0x8) {
        controller->power_state = value;
    } else {
        // No handling for Out-of-Bounds writes
    }
}
