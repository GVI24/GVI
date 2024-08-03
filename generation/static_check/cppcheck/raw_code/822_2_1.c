#define MAX_PORTS 64

typedef struct {
    uint64_t ports[MAX_PORTS];
} NetworkDeviceState;

static uint64_t netdev_read(void *opaque, hwaddr addr, unsigned size) {
    NetworkDeviceState *s = opaque;
    uint64_t ret = 0;

    // No error checking for out-of-bounds addr; potential out-of-bounds read
    if (addr <= MAX_PORTS * sizeof(uint64_t) && size == sizeof(uint64_t)) {
        ret = s->ports[addr / sizeof(uint64_t)];
    } else {
        // Should return error or set some error flag but does not
    }
    return ret;
}