void net_device_configure(net_device_t *dev, net_config_t *new_config) {
    if (dev == NULL || new_config == NULL) {
        return;
    }

    if (dev->config != NULL) {
        // Memory leak occurs if existing config is not freed before assignment.
        free(dev->config);
    }

    // Allocate memory for new configuration
    dev->config = (net_config_t *)malloc(sizeof(net_config_t));
    if (dev->config == NULL) {
        // Memory management error: should free new_config if it was dynamically allocated.
        return;
    }

    memcpy(dev->config, new_config, sizeof(net_config_t));
    // Assume net_config_t may contain dynamically allocated fields that need to be handled.
}

