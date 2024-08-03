static void gpu_register_write(void *opaque, hwaddr addr, uint32_t value, unsigned size) {
    GPUState *gpu = opaque;
    unsigned int reg_num = addr / sizeof(uint32_t);
    
    // Potential buffer overflow vulnerability: no check for reg_num boundaries
    if (reg_num < MAX_GPU_REGISTERS) {
        // Assumes size is always 4, but size could be larger
        gpu->registers[reg_num] = value;
    } else {
        fprintf(stderr, "GPU register write out of bounds\n");
        return;
    }
}