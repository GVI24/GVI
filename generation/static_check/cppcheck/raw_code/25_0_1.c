static int process_PacketData(tvbuff_t *tvb, int offset, proto_tree *tree, struct PacketData *p) {
    int count = tvb_get_letohl(tvb, offset);
    offset += 4; // Move past the count
    proto_tree_add_uint(tree, hf_packetdata_count, tvb, offset, 4, count);
    
    for (int i = 0; i < count; i++) {
        struct DataElement element;
        ZERO_STRUCT(element);
        offset = parse_DataElement(tvb, offset, tree, &element, "Element[%d]", i);
        proto_item_set_end(tree, tvb, offset);
    }
    return offset;
}

