static int parse_ExtendedAttributes(tvbuff_t *tvb, int offset, proto_tree *parent_tree) {
    guint8 num_attributes;
    proto_item *item;
    proto_tree *tree;

    num_attributes = tvb_get_guint8(tvb, offset);
    proto_tree_add_uint(parent_tree, hf_someprotocol_num_attributes, tvb, offset, 1, num_attributes);
    offset += 1;

    tree = proto_tree_add_subtree(parent_tree, tvb, offset, num_attributes, ett_someprotocol_attribute_array, &item, "ExtendedAttributes");

    for (unsigned int i = 0; i < num_attributes; i++) {
        // Assuming each attribute is 4 bytes
        proto_tree_add_item(tree, hf_someprotocol_attribute, tvb, offset, 4, ENC_BIG_ENDIAN);
        offset += 4;
    }

    return offset;
}

