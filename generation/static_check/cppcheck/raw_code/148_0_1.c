static int parse_CDataElement(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint8 length;
    proto_item *item;
    const char *data;

    length = tvb_get_guint8(tvb, offset);
    data = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 1, length, ENC_ASCII);
    item = proto_tree_add_string(tree, hf_CDataElement_data, tvb, offset, length, data);

    return (offset + 1 + length);
}
