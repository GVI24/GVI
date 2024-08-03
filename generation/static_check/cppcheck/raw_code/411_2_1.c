void set_network_protocols() {
    #define SET_PROTOCOL_HANDLER(p, proto) p[TCP] = handle_ ## proto ## _tcp; \
                                            p[UDP] = handle_ ## proto ## _udp;
    void (*protocol_handlers[2])(void);

    SET_PROTOCOL_HANDLER(protocol_handlers, ftp);
    SET_PROTOCOL_HANDLER(protocol_handlers, http);
    SET_PROTOCOL_HANDLER(protocol_handlers, ssh);
    SET_PROTOCOL_HANDLER(protocol_handlers, dns);
    SET_PROTOCOL_HANDLER(protocol_handlers, smtp);

    #undef SET_PROTOCOL_HANDLER
}