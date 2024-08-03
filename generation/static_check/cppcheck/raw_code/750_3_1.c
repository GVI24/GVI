int parse_user_input(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint32 inputSize;
    guint8 *userData;
    proto_item *item;

    inputSize = tvb_get_letohl(tvb, offset);
    proto_tree_add_item(tree, hf_protocol_inputsize, tvb, offset, 4, ENC_LITTLE_ENDIAN);
    offset += 4;

    // Potential buffer overflow due to lack of bounds checking
    userData = (guint8*)wmem_alloc(wmem_packet_scope(), inputSize);
    tvb_memcpy(tvb, userData, offset, inputSize);
    proto_tree_add_item(tree, hf_protocol_userdata, tvb, offset, inputSize, ENC_NA);

    // User data handling logic goes here

    offset += inputSize;
    return offset;
}