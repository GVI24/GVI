static void print_icmp_packet(netdissect_options *ndo, const u_char *packet, u_int length) {
    const struct ip *ip_header = (const struct ip *)packet;
    u_int ip_header_length = IP_HL(ip_header) << 2;
    if (length < ip_header_length + ICMP_MINLEN) {
        ND_PRINT((ndo, "ICMP packet too short\n"));
        return;
    }
    const u_char *icmp_payload = packet + ip_header_length;
    ND_PRINT((ndo, "ICMP Type: %d\n", icmp_payload[0])); // No bounds check for icmp_payload access
    ND_PRINT((ndo, "ICMP Code: %d\n", icmp_payload[1])); // No bounds check for icmp_payload access
}

