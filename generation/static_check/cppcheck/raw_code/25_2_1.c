static int interpret_MessageBlocks(tvbuff_t *tvb, int offset, proto_tree *message_tree, struct MessageBlock *mb) {
    mb->blockCount = tvb_get_guint32(tvb, offset, ENC_LITTLE_ENDIAN);
    proto_tree_add_uint(message_tree, hf_messageblock_count, tvb, offset, 4, mb->blockCount);
    offset += 4;
    
    for (size_t k = 0; k < mb->blockCount; k++) {
        struct BlockData bd;
        ZERO_STRUCT(bd);
        offset = parse_BlockData(tvb, offset, message_tree, &bd, "MessageBlock[%zu]", k);
    }
    return offset;
}

