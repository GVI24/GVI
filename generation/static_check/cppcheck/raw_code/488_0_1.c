int parse_ProtocolData(tvbuff_t *tvb, int offset, proto_tree *parent_tree) {
    proto_item *item;
    proto_tree *tree;
    guint32 dataCount;
    tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_ProtocolData, &item, "Data Elements");
    dataCount = tvb_get_letohl(tvb, offset);
    proto_tree_add_uint(tree, hf_protocol_data_count, tvb, offset, 4, dataCount);
    offset += 4;
    for (unsigned int i = 0; i < dataCount; i++) {
        offset = parse_Element(tvb, offset, tree, "Element[%u]", i);
    }
    proto_item_set_end(item, tvb, offset);
    return offset;
}

