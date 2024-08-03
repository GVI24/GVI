int device_reset(struct device_manager *dev_manager) {
    const struct device_operations *dev_ops = dev_manager->dev_ops;
    void *device_state = dev_manager->device_state;
    
    if (device_state && dev_ops->reset) {
        dev_ops->release(device_state);
        // Possible memory leak if release does not free device_state and it gets overwritten
    }

    device_state = dev_manager->device_state = dev_ops->init();
    if (!dev_manager->device_state) {
        log_error("Failed to reset the device");
        return -1;
    }

    return 0;
}

