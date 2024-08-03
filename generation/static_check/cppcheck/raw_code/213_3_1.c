static int parse_PayloadData(tvbuff_t *tvb, int offset, proto_tree *parent_tree) {
    guint16 data_count;
    proto_tree *tree;
    proto_item *item;

    data_count = tvb_get_ntohs(tvb, offset);
    proto_tree_add_uint(parent_tree, hf_someprotocol_data_count, tvb, offset, 2, data_count);
    offset += 2;

    tree = proto_tree_add_subtree_format(parent_tree, tvb, offset, data_count, ett_someprotocol_payload, &item, "PayloadData count: %u", data_count);

    for (int i = 0; i < data_count; i++) {
        // Assuming payload data consists of variable-length strings
        guint8 string_length = tvb_get_guint8(tvb, offset);
        proto_tree_add_item(tree, hf_someprotocol_payload_data, tvb, offset, string_length, ENC_ASCII | ENC_NA);
        offset += string_length;
    }

    return offset;
}