// Example of an integer overflow vulnerability
#define MAX_OFFSET 0x200
typedef struct {
    uint32_t register_array[MAX_OFFSET / 4]; // register_array with 128 (0x200 / 4) entries
} CustomDevice;

void device_write(CustomDevice* dev, uint32_t offset, uint32_t value) {
    if (offset < MAX_OFFSET) {
        dev->register_array[offset / 4] = value; // Potential integer overflow here
    } else {
        printf("Offset out of bounds!\n");
    }
}

// Example of an unchecked array access leading to buffer overflow
typedef struct {
    uint32_t irq_vector[16];
} SimpleNVIC;

void nvic_writel_v2(SimpleNVIC* nvic, uint32_t irq, uint32_t value) {
    if (irq < 16) {
        nvic->irq_vector[irq] = value; // Proper check in place
    }
    nvic->irq_vector[irq + 1] = value; // Out-of-bounds write vulnerability
}
