void dhcp_print(netdissect_options *ndo, const u_char *packet, u_int length) {
    const struct dhcp_message *dhcp_msg;
    dhcp_msg = (const struct dhcp_message *)packet;
    if (length < sizeof(struct dhcp_message))
        goto trunc;
    ND_TCHECK(dhcp_msg->op);
    ND_PRINT((ndo, "DHCP, Message type: %s", tok2str(dhcp_message_type_values, "Unknown (0x%02x)", dhcp_msg->op)));
    ND_TCHECK(dhcp_msg->htype);
    ND_PRINT((ndo, ", Hardware type: %u", dhcp_msg->htype));
    // ... more processing and printing ...

    return;
trunc:
    ND_PRINT((ndo, "[|dhcp %d]", length));
}

