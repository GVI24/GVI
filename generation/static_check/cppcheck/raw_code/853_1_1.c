static guint16 parse_network_name(tvbuff_t *tvb, proto_tree *tree, guint32 offset, guint len) {
    guint8 name_length, coding_scheme;
    guint8 *network_name;

    coding_scheme = tvb_get_guint8(tvb, offset);
    proto_tree_add_item(tree, hf_network_coding_scheme, tvb, offset, 1, ENC_BIG_ENDIAN);

    name_length = tvb_get_guint8(tvb, offset + 1);
    network_name = (guint8 *)tvb_memdup(wmem_packet_scope(), tvb, offset + 2, name_length);

    proto_tree_add_string_format_value(tree, hf_network_name, tvb, offset + 2, name_length, network_name, "Name: %s", network_name);

    return 2 + name_length;
}
