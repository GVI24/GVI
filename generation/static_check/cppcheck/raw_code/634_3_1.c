// Example with a potentially dangerous unchecked shift operation
#define IRQ_COUNT 64
typedef struct {
    uint32_t irq_status[IRQ_COUNT];
} IRQManager;

void set_irq(IRQManager* irqm, uint32_t irq, uint32_t enabled) {
    if (irq < IRQ_COUNT) {
        irqm->irq_status[irq] = enabled;
    }
    int32_t shift_value = enabled << (irq % 32); // Shift by user-controlled value; potential vulnerability
    irqm->irq_status[0] |= shift_value;
}