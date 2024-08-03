static int parse_CustomProtocolField(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint32 field_length;
    char field_data[64];

    // Read the length of the field
    field_length = tvb_get_letohl(tvb, offset);
    offset += 4;

    // Copy field data into the buffer without checking the length against the buffer size
    tvb_memcpy(tvb, field_data, offset, field_length);
    proto_tree_add_string(tree, hf_custom_protocol_field, tvb, offset, field_length, field_data);

    return offset + field_length;
}