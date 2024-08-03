static int storage_controller_init_pci(PCIDevice *pci_dev) {
    StorageControllerProxy *proxy = (StorageControllerProxy *)pci_dev;
    StorageDevice *sdev;
    
    if (proxy->class_code != PCI_CLASS_STORAGE_SCSI) {
        proxy->class_code = PCI_CLASS_STORAGE_SCSI;
    }
    
    sdev = storage_controller_init(&pci_dev->qdev);
    if (!sdev) {
        return -1;
    }
    
    storage_init_pci(proxy, sdev, PCI_VENDOR_ID_ANOTHER_VENDOR, PCI_DEVICE_ID_STORAGE_CONTROLLER, proxy->class_code, 0x00);
    return 0;
}
