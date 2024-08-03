static int extract_Headers(tvbuff_t *tvb, int offset, proto_tree *parent_tree) {
    guint32 headers_num;
    proto_item *item;
    proto_tree *tree;

    headers_num = tvb_get_ntohl(tvb, offset);
    item = proto_tree_add_uint(parent_tree, hf_header_count, tvb, offset, 4, headers_num);
    tree = proto_item_add_subtree(item, ett_headers);
    offset += 4;

    // Vulnerability: headers_num is not checked against the size of tvb.
    for (unsigned int i = 0; i < headers_num; i++) {
        proto_tree_add_item(tree, hf_header_item, tvb, offset, 10, ENC_NA);
        offset += 10;
    }
    return offset;
}