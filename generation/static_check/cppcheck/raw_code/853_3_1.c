static guint32 decode_sms(tvbuff_t *tvb, proto_tree *tree, guint32 offset, guint len) {
    guint32 curr_offset = offset;
    guint8 user_data_len;
    gchar *user_data;

    user_data_len = tvb_get_guint8(tvb, curr_offset);
    curr_offset++;

    user_data = (gchar *)tvb_memdup(wmem_packet_scope(), tvb, curr_offset, user_data_len);
    memcpy(user_data, tvb_get_ptr(tvb, curr_offset, user_data_len), user_data_len);

    proto_tree_add_string(tree, hf_sms_user_data, tvb, curr_offset, user_data_len, user_data);

    return curr_offset + user_data_len;
}