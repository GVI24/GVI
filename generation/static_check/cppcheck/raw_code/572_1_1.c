void icmp_print(netdissect_options *ndo, const u_char *packet, u_int length) {
    const struct icmp_header *icmp_hdr;
    icmp_hdr = (const struct icmp_header *)packet;
    if (length < sizeof(struct icmp_header))
        goto trunc;
    ND_TCHECK(icmp_hdr->type);
    ND_PRINT((ndo, "ICMP, Type: %s", tok2str(icmp_type_values, "Unknown (%u)", icmp_hdr->type)));
    ND_TCHECK(icmp_hdr->code);
    ND_PRINT((ndo, ", Code: %u", icmp_hdr->code));
    // ... more processing and printing ...

    return;
trunc:
    ND_PRINT((ndo, "[|icmp %d]", length));
}

