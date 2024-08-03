static int parse_OptionsField(tvbuff_t *tvb, int offset, proto_tree *parent_tree) {
    guint options_size;
    proto_tree *tree;
    proto_item *item;

    options_size = tvb_get_ntohs(tvb, offset);
    tree = proto_tree_add_subtree(parent_tree, tvb, offset, options_size, ett_someprotocol_options, &item, "OptionsField");
    offset += 2;

    for (int i = 0; i < options_size; i++) {
        // Process each option byte
        proto_tree_add_item(tree, hf_someprotocol_option, tvb, offset, 1, ENC_NA);
        offset += 1;
    }

    return offset;
}

