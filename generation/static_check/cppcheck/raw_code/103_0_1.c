static uint32_t read_cpu_register(void *opaque, hwaddr addr, unsigned size) {
    uint32_t reg_value = 0;
    CPUArchState *arch_state = get_current_cpu_arch_state();
    addr &= CPU_REGISTERS_MMIO_SIZE - 1;
    
    switch (addr) {
    case CPU_REG_ADDR_MSR:
        reg_value = arch_state->msr;
        break;
    case CPU_REG_ADDR_LR:
        reg_value = arch_state->lr;
        break;
    default:
        fprintf(stderr, "cpu: Invalid register read attempt: %x\n", addr);
        break;
    }
    return reg_value;
}