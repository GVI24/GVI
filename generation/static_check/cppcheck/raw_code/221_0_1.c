static int parse_CTypeDescriptor(tvbuff_t *tvb, int offset, proto_tree *parent_tree, proto_tree *pad_tree, struct CTypeDescriptor *v, const char *fmt, ...) {
    proto_tree *tree;
    proto_item *item;
    const char *txt;
    va_list ap;
    va_start(ap, fmt);
    txt = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
    va_end(ap);
    tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_CTypeDescriptor, &item, txt);
    v->type_code = tvb_get_guint8(tvb, offset);
    proto_tree_add_item(tree, hf_mswsp_ctype_descriptor_type_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
    offset += 1;
    offset = parse_CSimpleType(tvb, offset, tree, pad_tree, &v->simple_type, "Simple Type");
    proto_item_set_end(item, tvb, offset);
    return offset;
}

