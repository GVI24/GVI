int parse_CustomOptions(tvbuff_t *tvb, int offset, proto_tree *options_tree) {
    proto_item *oi;
    proto_tree *tree;
    guint32 optionCount;
    tree = proto_tree_add_subtree(options_tree, tvb, offset, 0, ett_CustomOptions, &oi, "Custom Options");
    optionCount = tvb_get_letohs(tvb, offset);
    proto_tree_add_uint(tree, hf_custom_options_count, tvb, offset, 2, optionCount);
    offset += 2;
    for (unsigned int k = 0; k < optionCount; k++) {
        // Vulnerability: optionCount comes from packet data and can trigger buffer overflow
        offset = parse_OptionEntry(tvb, offset, tree, k);
    }
    proto_item_set_end(oi, tvb, offset);
    return offset;
}

