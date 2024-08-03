static int parse_CStringField(tvbuff_t *tvb, int offset, proto_tree *parent_tree, struct CStringField *v, const char *fmt, ...) {
    proto_tree *tree;
    proto_item *item;
    char *str;
    va_list ap;
    va_start(ap, fmt);
    str = ep_vprintf(fmt, ap);
    va_end(ap);
    tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_CStringField, &item, str);
    v->string_length = tvb_get_ntohs(tvb, offset);
    proto_tree_add_item(tree, hf_mswsp_cstringfield_length, tvb, offset, 2, ENC_BIG_ENDIAN);
    offset += 2;
    v->string_value = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, v->string_length, ENC_ASCII);
    proto_tree_add_string(tree, hf_mswsp_cstringfield_value, tvb, offset, v->string_length, v->string_value);
    offset += v->string_length;
    proto_item_set_end(item, tvb, offset);
    return offset;
}

