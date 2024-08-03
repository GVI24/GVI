static int parse_CNodeRestriction(tvbuff_t *tvb, int offset, proto_tree *tree) {
    proto_item *item;
    gchar *label_format;
    gchar *label;

    label_format = tvb_format_text(tvb, offset, 50);
    label = g_strdup_printf(label_format); // potential format string vulnerability
    item = proto_tree_add_string(tree, hf_CNodeRestriction, tvb, offset, -1, label);
    g_free(label);
    
    // ... Additional parsing logic

    return offset;
}

