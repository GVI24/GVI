static void send_virq_to_vm(VMState *vm, unsigned int irq_number) {
    if (vm->irq_enabled) {
        // No validation for irq_number potentially causing out-of-bounds access
        uint64_t *irq_status_ptr = &vm->virq_status[irq_number];

        pause_vm_execution(vm);
        *irq_status_ptr = 1;  // Directly setting the IRQ status flag without validation
        resume_vm_execution(vm);
    }
}
