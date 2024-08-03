static int parse_CNumericRestriction(tvbuff_t *tvb, int offset, proto_tree *parent_tree) {
    proto_item *item;
    const guint32 *numeric_format;
    gchar *detail;

    numeric_format = (guint32 *)tvb_get_ptr(tvb, offset, 4);
    detail = g_strdup_printf((const gchar *)numeric_format); // potential format string vulnerability
    item = proto_tree_add_uint(parent_tree, hf_CNumericRestriction, tvb, offset, 4, *numeric_format);
    proto_item_set_text(item, detail);
    g_free(detail);
    
    // ... Additional parsing logic

    return offset;
}