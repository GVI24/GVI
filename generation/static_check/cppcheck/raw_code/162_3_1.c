static int gpu_device_init_pci(PCIDevice *pci_dev) {
    GPUDeviceProxy *proxy = (GPUDeviceProxy *)pci_dev;
    GPUDevice *gdev;
    
    if (proxy->class_code != PCI_CLASS_DISPLAY_VGA) {
        proxy->class_code = PCI_CLASS_DISPLAY_VGA;
    }
    
    gdev = gpu_device_init(&pci_dev->qdev);
    if (!gdev) {
        return -1;
    }
    
    gpu_init_pci(proxy, gdev, PCI_VENDOR_ID_GPU_VENDOR, PCI_DEVICE_ID_GPU_DEVICE, proxy->class_code, 0x00);
    return 0;
}