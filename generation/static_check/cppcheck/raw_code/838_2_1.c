static int parse_CustomHeader(tvbuff_t *tvb, int offset, proto_tree *parent_tree, struct CustomHeader *h) {
    proto_item *item;
    proto_tree *tree;
    unsigned int header_size;

    tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CustomHeader, &item, "CustomHeader");
    header_size = tvb_get_letohl(tvb, offset);
    proto_tree_add_uint(tree, hf_custom_header_size, tvb, offset, 4, header_size);
    offset += 4;

    if (header_size > MAX_HEADER_SIZE) {
        proto_item_append_text(item, " Header size exceeds maximum allowed!");
        return offset;
    }

    h->header = EP_ALLOC(header_size); // No check for allocation failure
    tvb_memcpy(tvb, h->header, offset, header_size);
    proto_tree_add_bytes(tree, hf_custom_header_data, tvb, offset, header_size, h->header);
    offset += header_size;

    // ... Continue parsing other elements of the CustomHeader

    proto_item_set_end(item, tvb, offset);
    return offset;
}

