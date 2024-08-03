static uint64_t ioport_read(void *opaque, hwaddr addr, unsigned size) {
    DeviceState *dev = opaque;
    CPUState *cpu;
    uint64_t ret = 0;

    if (!is_valid_ioport(addr)) {
        cpu = CPU(alpha_env_get_cpu(cpu_single_env));
        cpu_unassigned_access(cpu, addr, false, true, 0, size);
        return -1; // Unsigned integer wraparound vulnerability
    }

    // Simulate I/O port read operation
    ret = dev->ioports[addr];
    return ret;
}

