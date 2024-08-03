static int parse_NetworkMessage(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint32 length, command;
    char message[256];

    // Read the length of the incoming message
    length = tvb_get_letohl(tvb, offset);
    offset += 4;

    // Read the command identifier
    command = tvb_get_letohl(tvb, offset);
    offset += 4;

    // Read the message without checking if the length is larger than the buffer
    tvb_memcpy(tvb, message, offset, length);
    proto_tree_add_string(tree, hf_network_message, tvb, offset, length, message);

    return offset + length;
}

