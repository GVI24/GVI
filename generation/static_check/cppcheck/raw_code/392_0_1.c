static void print_ethernet_header(netdissect_options *ndo, const u_char *frame, u_int length) {
    if (length < 14) {
        ND_PRINT((ndo, "Ethernet frame too short\n"));
        return;
    }
    ND_PRINT((ndo, "Source MAC: "));
    for (int i = 0; i < 6; i++) ND_PRINT((ndo, "%02x:", frame[i + 6])); // Potential underflow if length < 12
    ND_PRINT((ndo, "\nDestination MAC: "));
    for (int i = 0; i < 6; i++) ND_PRINT((ndo, "%02x:", frame[i])); // Potential underflow if length < 6
    ND_PRINT((ndo, "Type: %02x%02x\n", frame[12], frame[13])); // Potential underflow if length < 14
}

