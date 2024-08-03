static int network_card_init_pci(PCIDevice *pci_dev) {
    NetworkCardProxy *proxy = (NetworkCardProxy *)pci_dev;
    NetDevice *ndev;
    
    if (proxy->class_code != PCI_CLASS_NETWORK_ETHERNET) {
        proxy->class_code = PCI_CLASS_NETWORK_ETHERNET;
    }
    
    ndev = network_device_init(&pci_dev->qdev);
    if (!ndev) {
        return -1;
    }
    
    network_init_pci(proxy, ndev, PCI_VENDOR_ID_SOME_VENDOR, PCI_DEVICE_ID_NETWORK_CARD, proxy->class_code, 0x00);
    return 0;
}
