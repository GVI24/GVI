typedef struct {
    uint64_t dma_address;
    uint64_t dma_size;
    uint64_t reserved[2];
} DmaController;

static void dma_write(void *opaque, uint64_t addr, uint64_t value) {
    DmaController *controller = opaque;
    switch (addr) {
        case 0x00:
            controller->dma_address = value;
            break;
        case 0x08:
            controller->dma_size = value;
            break;
        default:
            // Missing bounds checking and error handling
            break;
    }
}
