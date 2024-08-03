static uint64_t read_memory_controller_register(void *opaque, hwaddr addr, unsigned size) {
    uint64_t data = 0;
    SystemMemoryState *mem_state = get_system_memory_state();
    addr &= MEMORY_CONTROLLER_MMIO_SIZE - 1;
    
    switch (addr) {
    case MEM_CTRL_REG_CONFIG:
        data = mem_state->config_reg;
        break;
    case MEM_CTRL_REG_STATUS:
        data = mem_state->status_reg;
        break;
    default:
        fprintf(stderr, "memory controller: Unrecognized register access: %x\n", addr);
        break;
    }
    return data;
}