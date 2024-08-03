static int processNetworkPacket(struct connection *conn, const unsigned char *packet, unsigned int packetLen) {
    unsigned int consumed = 0;
    int parseResult;

    while (consumed < packetLen) {
        // Vulnerable line: No check for underflow in subtraction
        parseResult = parsePacketData(conn->parser, packet + consumed, packetLen - consumed);
        if (parseResult <= 0) {
            // Error handling
            if (parseResult < 0) {
                fprintf(stderr, "Parsing packet data failed\n");
                return -1;
            } else {
                // The parsing function cannot proceed further at this moment
                break;
            }
        }
        // Vulnerable line: No check for overflow when incrementing consumed
        consumed += parseResult;
    }
    return consumed;
}