bool apply_network_config(connection_t *c) {
    char ip_address[16];
    char subnet_mask[16];
    char gateway[16];
    int ret;

    // Vulnerability: No bounds checking for 'ip_address', 'subnet_mask', 'gateway'
    ret = sscanf(c->buffer, "%15s %15s %15s", ip_address, subnet_mask, gateway);
    if (ret != 3) {
        logger(LOG_ERR, "Invalid network configuration format from %s", c->hostname);
        return false;
    }

    // Apply network settings
    if (!set_network_configuration(ip_address, subnet_mask, gateway)) {
        // Vulnerability: Logging user-controllable input
        logger(LOG_ERR,"Network config application error: %s", c->buffer);
        return false;
    }

    return true;
}