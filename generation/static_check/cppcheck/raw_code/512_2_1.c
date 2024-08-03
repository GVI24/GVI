static void extract_network_info(tvbuff_t *tvb, proto_tree *tree, guint *offset) {
    proto_tree *sub_tree = NULL;
    guint8 node_count;
    node_count = tvb_get_guint8(tvb, *offset);
    proto_tree_add_item(tree, hf_node_count, tvb, *offset, 1, ENC_NA);
    *offset += 1;
    for (guint i = 0; i < node_count; i++) {
        sub_tree = proto_tree_add_subtree_format(tree, tvb, *offset, 3, ett_network_nodes[i], NULL, "Node Info #%u", i);
        extract_node(tvb, sub_tree, offset);
    }
}

