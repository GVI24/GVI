static int parse_CValueList(tvbuff_t *tvb, int offset, proto_tree *parent_tree, struct CValueList *v, const char *fmt, ...) {
    proto_tree *tree;
    proto_item *item;
    char *display_str;
    va_list ap;
    int i;
    va_start(ap, fmt);
    display_str = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
    va_end(ap);
    tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_CValueList, &item, display_str);
    v->count = tvb_get_ntohl(tvb, offset);
    proto_tree_add_item(tree, hf_mswsp_cvaluelist_count, tvb, offset, 4, ENC_BIG_ENDIAN);
    offset += 4;
    v->values = wmem_alloc_array(wmem_packet_scope(), sizeof(float), v->count);
    for (i = 0; i < v->count; i++) {
        v->values[i] = tvb_get_letohieee_float(tvb, offset);
        offset += 4;
        proto_tree_add_float(tree, hf_mswsp_cvaluelist_value, tvb, offset, 4, v->values[i]);
    }
    proto_item_set_end(item, tvb, offset);
    return offset;
}

