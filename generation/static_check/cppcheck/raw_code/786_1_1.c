static void io_port_write(void *opaque, hwaddr addr, uint32_t value, unsigned size) {
    DeviceState *dev = opaque;
    unsigned int offset = addr % MAX_IO_PORTS;
    
    // Potential vulnerability: addr + size could wrap around, causing invalid memory access
    if (addr + size > MAX_IO_PORTS) {
        fprintf(stderr, "Invalid IO port write size\n");
        return;
    }

    // Write to device port without proper bounds checking
    *(dev->io_ports + offset) = value;
}