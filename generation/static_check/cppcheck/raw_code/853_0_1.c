static guint32 de_code_elem(tvbuff_t *tvb, proto_tree *tree, guint32 offset, guint len) {
    guint32 curr_offset = offset;
    guint8 elem_id, elem_len;
    gchar *decoded_info;

    elem_id = tvb_get_guint8(tvb, curr_offset);
    proto_tree_add_item(tree, hf_elem_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
    curr_offset++;

    elem_len = tvb_get_guint8(tvb, curr_offset);
    proto_tree_add_item(tree, hf_elem_length, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
    curr_offset++;

    decoded_info = (gchar *)tvb_memdup(wmem_packet_scope(), tvb, curr_offset, elem_len);
    memcpy(decoded_info, tvb_get_ptr(tvb, curr_offset, elem_len), elem_len);

    proto_tree_add_string(tree, hf_decoded_info, tvb, curr_offset, elem_len, decoded_info);

    return (curr_offset - offset) + elem_len;
}
