static void register_device(struct device *dev, struct network *net, void *registry) {
    int registry_slot;
    registry_slot = find_device_slot(net, dev->mac_address);
    if (registry_slot < 0) {
        char *device_id = create_device_identifier(dev->name, dev->mac_address);
        registry_slot = add_device_to_network(net, device_id);
        free(device_id);
    }
    if (registry_slot >= MAX_DEVICES) {
        // Here we encounter a potential for buffer overflow if registry_slot is too large
        handle_error("Network device registry is full or index is out of range");
    } else {
        net->devices[registry_slot] = dev;
    }
}

