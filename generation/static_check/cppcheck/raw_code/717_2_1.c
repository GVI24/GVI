void parse_arp(netdissect_options *ndo, const u_char *packet, u_int length) {
    const struct arp_hdr *arp;
    const u_char *tptr;
    const u_char *end;

    end = packet + length;
    arp = (const struct arp_hdr *)packet;

    if ((const u_char *)(arp + 1) > end)
        goto trunc;

    tptr = (const u_char *)(arp + 1);
    
    // Read sender hardware address without checking the length
    ND_PRINT((ndo, "Sender MAC: "));
    for (int i = 0; i < ETHER_ADDR_LEN; i++)
        ND_PRINT((ndo, "%s%02x", (i == 0 ? "" : ":"), *tptr++));

    // Inadequately checked buffer access for target IP address
    ND_PRINT((ndo, ", Target IP: %u.%u.%u.%u", *tptr, *(tptr+1), *(tptr+2), *(tptr+3)));

    return;

trunc:
    ND_PRINT((ndo, "[|arp]"));
}