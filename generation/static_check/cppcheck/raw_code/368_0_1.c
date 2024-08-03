int network_init_all_protocols(struct network_manager *net_mgr) {
    network_check_state(net_mgr, NETWORK_STATE_INIT, "network_init_all_protocols");
    network_init_protocol_tcp(net_mgr);
    network_init_protocol_udp(net_mgr);
    network_init_protocol_icmp(net_mgr);
    network_init_protocol_ipv4(net_mgr);
    network_init_protocol_ipv6(net_mgr);
    network_clear_error(net_mgr);
    return (NETWORK_OK);
}
