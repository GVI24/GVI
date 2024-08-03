void arp_print(netdissect_options *ndo, const u_char *packet, u_int length) {
    const struct arp_header *arp_hdr;
    arp_hdr = (const struct arp_header *)packet;
    if (length < sizeof(struct arp_header))
        goto trunc;
    ND_TCHECK(arp_hdr->hardware_type);
    ND_PRINT((ndo, "ARP, Hardware type: %s", tok2str(arp_hardware_values, "Unknown (0x%04x)", EXTRACT_16BITS(&arp_hdr->hardware_type))));
    ND_TCHECK(arp_hdr->protocol_type);
    ND_PRINT((ndo, ", Protocol type: %s", tok2str(ethertype_values, "Unknown (0x%04x)", EXTRACT_16BITS(&arp_hdr->protocol_type))));
    // ... more processing and printing ...

    return;
trunc:
    ND_PRINT((ndo, "[|arp %d]", length));
}

