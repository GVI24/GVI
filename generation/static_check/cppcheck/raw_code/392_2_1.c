static void print_tcp_segment(netdissect_options *ndo, const u_char *segment, u_int length) {
    if (length < sizeof(struct tcphdr)) {
        ND_PRINT((ndo, "TCP segment too short\n"));
        return;
    }
    const struct tcphdr *tcp_header = (const struct tcphdr *)segment;
    int src_port = ntohs(tcp_header->th_sport);
    int dst_port = ntohs(tcp_header->th_dport);
    ND_PRINT((ndo, "Source port: %d, Destination port: %d\n", src_port, dst_port));
    u_int tcp_header_length = TH_OFF(tcp_header) << 2;
    const u_char *tcp_payload = segment + tcp_header_length;
    ND_PRINT((ndo, "Payload: %s\n", tcp_payload)); // No check if tcp_payload exceeds the segment length
}

