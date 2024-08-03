int decode_message(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint32 messageLength;
    guint8* messageData;
    proto_item *item;

    messageLength = tvb_get_letohl(tvb, offset);
    proto_tree_add_item(tree, hf_protocol_messagelength, tvb, offset, 4, ENC_LITTLE_ENDIAN);
    offset += 4;

    // Potential buffer overflow if messageLength is larger than remaining buffer size
    messageData = (guint8*)malloc(messageLength);
    tvb_memcpy(tvb, messageData, offset, messageLength);
    proto_tree_add_item(tree, hf_protocol_messagedata, tvb, offset, messageLength, ENC_NA);

    offset += messageLength;
    free(messageData);
    return offset;
}

