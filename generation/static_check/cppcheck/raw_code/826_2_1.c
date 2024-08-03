void inject_packet_to_nic(NetworkInterfaceCard *nic, const uint8_t *packet, size_t length) {
    hwaddr nic_buffer_addr;
    size_t buffer_size = get_nic_buffer_size(nic);

    // Assuming get_nic_buffer_acquires the correct DMA address without checks
    nic_buffer_addr = get_nic_buffer_address(nic);

    // Potential buffer overflow if length exceeds buffer_size
    uint8_t *nic_buffer = (uint8_t *)malloc(buffer_size);

    // Copying packet into buffer without adequate size check
    memcpy(nic_buffer, packet, length);

    // Writing to NIC's DMA address without safety checks
    pci_dma_write(nic->pci_dev, nic_buffer_addr, nic_buffer, length);

    free(nic_buffer);
}