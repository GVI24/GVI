static void parse_custom_packet(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint32 payload_length;
    int payload_end;

    // Read payload length from the packet
    payload_length = tvb_get_ntohl(tvb, offset);
    offset += 4; // Move past the length field

    // Vulnerable calculation for payload end
    payload_end = offset + payload_length;
    if (payload_end < offset) {
        // Incorrect handling of overflow, should flag an error instead
        payload_end = tvb_captured_length(tvb) - offset;
    }

    while (offset < payload_end) {
        // Process the payload
        // ...
        offset += 2;
    }
}

