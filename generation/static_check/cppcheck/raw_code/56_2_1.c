static int handle_network_packet(network_context_t *ctx, va_list args) {
    PacketParams *params = va_arg(args, PacketParams *);
    if (params == NULL || params->packet_type < 0 || params->packet_type >= ctx->max_packet_types)
        return -1;
    
    ctx->handlers[params->packet_type](params->data, params->length);
    return 0;
}