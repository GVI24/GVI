static uint64_t peripheral_read(void *opaque, hwaddr addr, unsigned size) {
    PeripheralDevice *pdev = opaque;
    CPUState *cpu;
    uint64_t ret = 0;

    if (!valid_peripheral_address(pdev, addr)) {
        cpu = CPU(alpha_env_get_cpu(cpu_single_env));
        cpu_unassigned_access(cpu, addr, false, false, 0, size);
        return -1; // Unsigned integer wraparound vulnerability
    }

    // Simulate peripheral device read operation
    ret = read_peripheral(pdev, addr);
    return ret;
}