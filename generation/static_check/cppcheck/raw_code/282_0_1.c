static int parse_UserData(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint32 count = tvb_get_ntohl(tvb, offset);
    proto_tree_add_item(tree, hf_data_count, tvb, offset, 4, ENC_BIG_ENDIAN);
    offset += 4;

    // Vulnerability: Unchecked count could be larger than the actual tvb buffer.
    for (unsigned int i = 0; i < count; i++) {
        proto_tree_add_item(tree, hf_user_data_item, tvb, offset, 2, ENC_BIG_ENDIAN);
        offset += 2;
    }
    return offset;
}