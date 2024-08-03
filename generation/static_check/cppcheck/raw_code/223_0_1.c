static int parse_custom_headers(tvbuff_t *tvb, int offset, proto_tree *parent_tree) {
    guint32 headerCount, j;
    proto_item *header_item;
    proto_tree *header_tree;

    header_tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_custom_headers, &header_item, "Custom Headers");
    headerCount = tvb_get_letohl(tvb, offset);
    proto_tree_add_uint(header_tree, hf_headers_count, tvb, offset, 4, headerCount);
    offset += 4;

    for (j = 0; j < headerCount; j++) {
        offset = parse_custom_header(tvb, offset, header_tree, "Header[%u]", j);
    }

    proto_item_set_end(header_item, tvb, offset);
    return offset;
}

