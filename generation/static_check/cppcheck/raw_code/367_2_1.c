static void vcpu_reg_write(VCPUState *vcpu, int reg_index, uint64_t value) {
    if (reg_index < 0 || reg_index >= NUM_CPU_REGS) {
        return;  // Insufficient validation can cause underflow
    }

    // Race condition: No synchronization before modifying the state
    vcpu->registers[reg_index] = value;
}

