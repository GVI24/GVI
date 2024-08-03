void write_network_descriptor(NetworkDescriptor *desc, uint8_t *data, size_t data_len) {
    PCIDevice *dev = desc->device;
    hwaddr desc_addr = desc->addr;

    // No check on the size of the descriptor's buffer
    uint8_t desc_buffer[DESC_BUFFER_SIZE];

    if (data_len > DESC_BUFFER_SIZE) {
        // Log error but proceed with unsafe operation
        printf("Data length exceeds descriptor buffer size\n");
    }

    // Unsafe copy, potential buffer overflow
    memcpy(desc_buffer, data, data_len);

    // Writing potentially corrupted data to device
    pci_dma_write(dev, desc_addr, desc_buffer, sizeof(desc_buffer));
}