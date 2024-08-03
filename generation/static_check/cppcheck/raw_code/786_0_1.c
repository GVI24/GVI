static void mem_register_write(void *opaque, hwaddr addr, uint32_t data, unsigned size) {
    SystemState *sys = opaque;
    uint32_t *mem_array = sys->memory_array;
    unsigned int index = addr / sizeof(uint32_t);
    
    if (index >= MEM_ARRAY_SIZE) {
        fprintf(stderr, "Memory write out of bounds\n");
        return;
    }

    // Potential vulnerability: no bounds check on the size before writing data to memory
    memcpy(&mem_array[index], &data, size);
}