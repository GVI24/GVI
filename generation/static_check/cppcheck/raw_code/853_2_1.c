static void decode_digit_pairs(tvbuff_t *tvb, proto_tree *tree, guint32 offset, guint len) {
    guint8 pair_count = len / 2;
    guint8 *digit_pairs = (guint8 *)tvb_memdup(wmem_packet_scope(), tvb, offset, pair_count);
    for (guint i = 0; i < pair_count; i++) {
        guint8 high_nibble = (digit_pairs[i] & 0xF0) >> 4;
        guint8 low_nibble = digit_pairs[i] & 0x0F;
        proto_tree_add_uint(tree, hf_digit_pair_high, tvb, offset + i, 1, high_nibble);
        proto_tree_add_uint(tree, hf_digit_pair_low, tvb, offset + i, 1, low_nibble);
    }
}
