static uint64_t cfgreg_read(void *opaque, hwaddr addr, unsigned size) {
    ConfigRegister *cfg = opaque;
    CPUState *cpu;
    uint64_t ret = 0;

    // Assuming cfg->num_regs holds the number of configuration registers
    if (addr / sizeof(uint64_t) >= cfg->num_regs) {
        cpu = CPU(alpha_env_get_cpu(cpu_single_env));
        cpu_unassigned_access(cpu, addr, false, false, 0, size);
        return -1; // Unsigned integer wraparound vulnerability
    }

    // Simulate configuration register read operation
    ret = cfg->regs[addr / sizeof(uint64_t)];
    return ret;
}

