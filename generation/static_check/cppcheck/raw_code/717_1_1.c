void read_icmp_packet(netdissect_options *ndo, const u_char *packet, u_int packet_len) {
    const struct icmp *icmp_header;
    const u_char *end;

    end = packet + packet_len;
    icmp_header = (const struct icmp *)packet;

    if ((const u_char *)(icmp_header + 1) > end)
        goto trunc;
    
    ND_PRINT((ndo, "ICMP type=%u, code=%u", icmp_header->icmp_type, icmp_header->icmp_code));
    
    // Assumes the rest of the packet is valid without checking
    const u_char *data = (const u_char *)(icmp_header + 1);
    int data_len = end - data;
    if (data_len > 0) {
        ND_PRINT((ndo, ", data length=%d", data_len));
    }

    return;

trunc:
    ND_PRINT((ndo, "[|icmp]"));
}