#include <stdint.h>
#include <stdio.h>

// Example of a buffer overflow due to lack of bounds checking
#define MAX_INTERRUPTS 32
typedef struct {
    uint32_t enabled[MAX_INTERRUPTS];
} InterruptController;

void enable_interrupt(InterruptController* ic, uint32_t interrupt_number) {
    if (interrupt_number < MAX_INTERRUPTS) {
        ic->enabled[interrupt_number] = 1; // Correct bounds check
    } else {
        printf("Invalid interrupt number!\n");
    }
}

void disable_interrupt(InterruptController* ic, uint32_t interrupt_number) {
    ic->enabled[interrupt_number] = 0; // Missing bounds check
}
