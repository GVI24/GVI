static int parse_CStatusMessage(tvbuff_t *tvb, int offset, proto_tree *parent_tree, struct CStatusMessage *v, const char *fmt, ...) {
    proto_tree *tree;
    proto_item *item;
    char *status_msg;
    va_list ap;
    va_start(ap, fmt);
    status_msg = wmem_strdup_vprintf(wmem_packet_scope(), fmt, ap);
    va_end(ap);
    tree = proto_tree_add_subtree_format(parent_tree, tvb, offset, -1, ett_CStatusMessage, &item, "Status: %s", status_msg);
    v->status_code = tvb_get_ntohs(tvb, offset);
    proto_tree_add_item(tree, hf_mswsp_cstatusmessage_code, tvb, offset, 2, ENC_BIG_ENDIAN);
    offset += 2;
    v->message = g_strdup(status_msg); // This could also be a potential memory leak if not freed properly
    proto_tree_add_string(tree, hf_mswsp_cstatusmessage_message, tvb, offset, -1, v->message);
    proto_item_set_end(item, tvb, offset);
    return offset;
}