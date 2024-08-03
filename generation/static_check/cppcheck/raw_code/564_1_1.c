static int parse_PacketHeader(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint16 header_type;
    char header_value[128];

    // Read the header type
    header_type = tvb_get_letohs(tvb, offset);
    offset += 2;

    // Dangerous: assumes there's always a 128-byte header without verification
    tvb_memcpy(tvb, header_value, offset, 128);
    proto_tree_add_string(tree, hf_packet_header_value, tvb, offset, 128, header_value);

    return offset + 128;
}

