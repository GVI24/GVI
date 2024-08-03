static void dma_controller_write(void *opaque, hwaddr addr, uint32_t value, unsigned size) {
    DMAController *controller = opaque;
    uint64_t dma_addr;

    // Potential vulnerability: Address calculation from user-supplied value without validation
    dma_addr = controller->base_addr + addr;

    // Directly writing to calculated address without any validation
    *(uint32_t *)(dma_addr) = value;
}