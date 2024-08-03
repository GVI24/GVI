void adjust_packet_qos(NetworkContext *net_ctx) {
    int base_qos = net_ctx->base_qos;
    int qos_levels[MAX_QOS_LEVELS];
    int i;

    for (i = LOWEST_QOS; i <= HIGHEST_QOS + 1; i++) { // Off-by-one error
        // Vulnerability: Potential out-of-bounds write
        qos_levels[i] = calculate_qos_level(base_qos, net_ctx->traffic_history[i]);
        set_qos(&net_ctx->packets[i], qos_levels[i]);
    }
}