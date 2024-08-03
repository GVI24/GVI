static uint64_t mem_read(void *opaque, hwaddr addr, unsigned size) {
    SystemMemory *mem = opaque;
    CPUState *cpu;
    uint64_t ret = 0;

    if (addr >= mem->size) {
        cpu = CPU(alpha_env_get_cpu(cpu_single_env));
        cpu_unassigned_access(cpu, addr, false, false, 0, size);
        return -1; // Unsigned integer wraparound vulnerability
    }

    // Simulate memory read operation
    ret = *(uint64_t *)(mem->data + addr);
    return ret;
}

