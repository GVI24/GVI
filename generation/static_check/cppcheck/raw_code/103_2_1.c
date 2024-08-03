static uint32_t read_network_controller_stat(void *opaque, hwaddr addr, unsigned size) {
    uint32_t status = 0;
    NetworkControllerState *net_state = get_network_controller_state();
    addr &= NETWORK_CONTROLLER_MMIO_SIZE - 1;
    
    switch (addr) {
    case NET_CTRL_REG_RX_STATUS:
        status = net_state->rx_status;
        break;
    case NET_CTRL_REG_TX_STATUS:
        status = net_state->tx_status;
        break;
    default:
        fprintf(stderr, "network controller: Unexpected register fetch: %x\n", addr);
        break;
    }
    return status;
}