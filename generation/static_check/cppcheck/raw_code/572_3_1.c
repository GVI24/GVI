void dns_print(netdissect_options *ndo, const u_char *packet, u_int length) {
    const struct dns_header *dns_hdr;
    dns_hdr = (const struct dns_header *)packet;
    if (length < sizeof(struct dns_header))
        goto trunc;
    ND_TCHECK(dns_hdr->transaction_id);
    ND_PRINT((ndo, "DNS, Transaction ID: 0x%04x", EXTRACT_16BITS(&dns_hdr->transaction_id)));
    ND_TCHECK(dns_hdr->flags);
    ND_PRINT((ndo, ", Flags: 0x%04x", EXTRACT_16BITS(&dns_hdr->flags)));
    // ... more processing and printing ...

    return;
trunc:
    ND_PRINT((ndo, "[|dns %d]", length));
}