static uint32_t pci_config_read(void *opaque, hwaddr addr, unsigned size) {
    uint32_t config_data = 0;
    PCIDeviceState *pci_state = get_pci_device_state();
    addr &= PCI_CONFIG_MMIO_SIZE - 1;
    
    switch (addr) {
    case PCI_CONFIG_REG_VENDOR_ID:
        config_data = pci_state->vendor_id;
        break;
    case PCI_CONFIG_REG_DEVICE_ID:
        config_data = pci_state->device_id;
        break;
    default:
        fprintf(stderr, "pci: Unknown configuration space read: %x\n", addr);
        break;
    }
    return config_data;
}