static int decode_Entries(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint32 entry_count;
    entry_count = tvb_get_ntohl(tvb, offset);
    proto_tree_add_item(tree, hf_entry_count, tvb, offset, 4, ENC_BIG_ENDIAN);
    offset += 4;

    // Vulnerability: entry_count is not verified to be within the bounds of tvb.
    for (int i = 0; i < entry_count; i++) {
        char entry_label[32];
        snprintf(entry_label, sizeof(entry_label), "Entry %d", i);
        proto_tree_add_string(tree, hf_entry_label, tvb, offset, 16, entry_label);
        offset += 16;
    }
    return offset;
}