int net_handle_packet(net_state *nstate) {
    int code = 0;
    net_packet *npack;
    code = net_allocate_packet(&npack, nstate->memory);
    if (code < 0) return code;

    net_init_packet(npack, nstate->memory, 0);
    if (nstate->current_packet != NULL) {
        if ((code = net_process_packet(nstate->current_packet, &npack->data)) < 0)
            return code;
        net_hold_data(npack->data);
    }

    if ((code = net_set_active_packet(nstate, npack)) < 0) {
        net_free_packet(nstate->memory, npack, "net_allocate_packet(current_packet)");
        // Missing free for npack->data if net_process_packet was successful
    }

    return code;
}

