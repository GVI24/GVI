static int audio_device_init_pci(PCIDevice *pci_dev) {
    AudioDeviceProxy *proxy = (AudioDeviceProxy *)pci_dev;
    AudioDevice *adev;
    
    if (proxy->class_code != PCI_CLASS_MULTIMEDIA_AUDIO_DEVICE) {
        proxy->class_code = PCI_CLASS_MULTIMEDIA_AUDIO_DEVICE;
    }
    
    adev = audio_device_init(&pci_dev->qdev);
    if (!adev) {
        return -1;
    }
    
    audio_init_pci(proxy, adev, PCI_VENDOR_ID_SOME_OTHER_VENDOR, PCI_DEVICE_ID_AUDIO_DEVICE, proxy->class_code, 0x00);
    return 0;
}
