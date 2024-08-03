int parse_PacketExtensions(tvbuff_t *tvb, int offset, proto_tree *ext_tree) {
    proto_item *ei;
    proto_tree *tree;
    guint32 extCount;
    tree = proto_tree_add_subtree(ext_tree, tvb, offset, 0, ett_PacketExtensions, &ei, "Packet Extensions");
    extCount = tvb_get_ntoh24(tvb, offset);  // 24-bit network byte order integer
    proto_tree_add_uint(tree, hf_packet_extensions_count, tvb, offset, 3, extCount);
    offset += 3;
    for (unsigned int m = 0; m < extCount; m++) {
        // Vulnerability: No check if extCount exceeds expected number of extensions
        offset = parse_Extension(tvb, offset, tree, "Extension[%u]", m);
    }
    proto_item_set_end(ei, tvb, offset);
    return offset;
}