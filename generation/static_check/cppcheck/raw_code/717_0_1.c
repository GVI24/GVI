void parse_dhcp_options(netdissect_options *ndo, const u_char *packet, int length) {
    const u_char *tptr;
    int opcode, op_len;

    tptr = packet;
    while (tptr < packet + length) {
        opcode = *tptr++;
        if (opcode == 255) // End Option
            break;

        op_len = *tptr++;
        if (tptr + op_len > packet + length)
            goto trunc;

        // Process option based on opcode
        ND_PRINT((ndo, "DHCP Option %u, length %u: ", opcode, op_len));
        tptr += op_len;
    }
    return;

trunc:
    ND_PRINT((ndo, "[|dhcp]"));
}