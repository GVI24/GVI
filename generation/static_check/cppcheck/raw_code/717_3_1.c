void decode_dns_question(netdissect_options *ndo, const u_char *packet, u_int length) {
    const u_char *tptr;
    const u_char *end;
    int qname_len;

    tptr = packet;
    end = packet + length;
    
    // Process DNS questions
    while (tptr < end) {
        qname_len = *tptr++; // length of the QNAME
        
        // Missing bounds check for qname_len
        ND_PRINT((ndo, "QNAME: "));
        while (qname_len--) {
            ND_PRINT((ndo, "%c", *tptr++));
            if (tptr >= end)
                goto trunc;
        }
        
        // Not checking enough bytes available for QTYPE and QCLASS
        ND_PRINT((ndo, ", QTYPE: %u, QCLASS: %u", EXTRACT_16BITS(tptr), EXTRACT_16BITS(tptr + 2)));
        tptr += 4; // Advance past QTYPE and QCLASS
    }
    return;

trunc:
    ND_PRINT((ndo, "[|dns]"));
}