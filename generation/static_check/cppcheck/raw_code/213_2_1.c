static int parse_ComplexType(tvbuff_t *tvb, int offset, proto_tree *parent_tree) {
    guint8 type_count;
    proto_tree *tree;
    proto_item *item;

    type_count = tvb_get_guint8(tvb, offset);
    proto_tree_add_uint(parent_tree, hf_someprotocol_type_count, tvb, offset, 1, type_count);
    offset += 1;

    tree = proto_tree_add_subtree(parent_tree, tvb, offset, type_count, ett_someprotocol_type_array, &item, "ComplexType");

    for (int i = 0; i < type_count; i++) {
        // Assuming each type has a fixed size of 8 bytes
        proto_tree_add_item(tree, hf_someprotocol_type, tvb, offset, 8, ENC_LITTLE_ENDIAN);
        offset += 8;
    }

    return offset;
}

