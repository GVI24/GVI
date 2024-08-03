static void parse_device_commands(tvbuff_t *tvb, proto_tree *tree, guint *offset) {
    proto_tree *sub_tree = NULL;
    guint8 command_count;
    command_count = tvb_get_guint8(tvb, *offset);
    proto_tree_add_item(tree, hf_command_count, tvb, *offset, 1, ENC_NA);
    *offset += 1;
    for (guint i = 0; i < command_count; i++) {
        sub_tree = proto_tree_add_subtree_format(tree, tvb, *offset, 2, ett_command_list[i], NULL, "Command ID #%u", i);
        parse_command(tvb, sub_tree, offset);
    }
}

