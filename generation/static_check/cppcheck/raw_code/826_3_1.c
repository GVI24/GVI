void handle_received_packets(struct RingBuffer *ring, EthernetFrame *frames, int frame_count) {
    for (int i = 0; i < frame_count; ++i) {
        hwaddr next_write_addr = ring->current_addr + ring->write_offset;

        // No check for the end of the ring buffer or available space
        uint8_t frame_buffer[MAX_FRAME_SIZE];

        // Potential buffer overflow from frames[i].data
        memcpy(frame_buffer, frames[i].data, frames[i].length);

        // Writing frame directly to ring buffer without checking its limits
        pci_dma_write(ring->pci_device, next_write_addr, frame_buffer, frames[i].length);

        // Unsafe update of write offset, may exceed buffer boundary
        ring->write_offset += frames[i].length;
    }
}