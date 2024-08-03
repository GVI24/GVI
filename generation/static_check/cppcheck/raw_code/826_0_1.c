void process_packet_to_vm(uint8_t *pkt_data, size_t pkt_len, VMNetworkAdapter *adapter) {
    uint8_t buffer[MAX_PACKET_SIZE];
    if (pkt_len > MAX_PACKET_SIZE) {
        // Improper packet size handling can lead to buffer overflow
        printf("Packet size too large\n");
        return;
    }

    // Unsafe copy operation without bounds checking
    memcpy(buffer, pkt_data, pkt_len);

    // Simulated write to VM through DMA, without validation
    vm_dma_write(adapter, buffer, pkt_len);
}