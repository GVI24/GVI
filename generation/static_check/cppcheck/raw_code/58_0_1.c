static int parse_CStreamRestriction(tvbuff_t *tvb, int offset, proto_tree *parent_tree, struct CStreamRestriction *v) {
    proto_item *item;
    const char *fmt;
    char buffer[256];

    fmt = tvb_get_string(tvb, offset, 100);
    snprintf(buffer, sizeof(buffer), fmt); // potential format string vulnerability
    item = proto_tree_add_item(parent_tree, hf_CStreamRestriction, tvb, offset, -1, ENC_NA);
    proto_item_set_text(item, buffer);
    
    // ... Additional parsing logic

    return offset;
}

