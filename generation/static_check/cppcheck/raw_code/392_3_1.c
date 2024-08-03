static void parse_custom_protocol(netdissect_options *ndo, const u_char *message, u_int length) {
    if (length < 3) {
        ND_PRINT((ndo, "Custom protocol message too short\n"));
        return;
    }
    u_int8_t msg_type = message[0];
    u_int16_t payload_length = ntohs(*(u_int16_t *)(message + 1));
    if (length < payload_length + 3) {
        ND_PRINT((ndo, "Custom protocol message length mismatch\n"));
        return;
    }
    const u_char *payload = message + 3;
    ND_PRINT((ndo, "Message Type: %d, Payload: ", msg_type));
    for (u_int i = 0; i < payload_length; i++) ND_PRINT((ndo, "%02x ", payload[i])); // No bounds check on payload_length
}