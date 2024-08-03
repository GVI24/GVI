static int process_CommandList(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint32 cmd_num, i;
    cmd_num = tvb_get_letohl(tvb, offset);
    proto_tree_add_item(tree, hf_command_num, tvb, offset, 4, ENC_LITTLE_ENDIAN);
    offset += 4;

    // Vulnerability: cmd_num could be manipulated to cause buffer overflow.
    for (i = 0; i < cmd_num; i++) {
        proto_tree_add_item(tree, hf_command_data, tvb, offset, 8, ENC_LITTLE_ENDIAN);
        offset += 8;
    }
    return offset;
}