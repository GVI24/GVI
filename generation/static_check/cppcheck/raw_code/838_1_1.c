static int parse_UserDataPacket(tvbuff_t *tvb, int offset, proto_tree *parent_tree, struct UserDataPacket *u) {
    proto_item *item;
    proto_tree *tree;
    unsigned int user_data_size;

    tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_UserDataPacket, &item, "UserDataPacket");
    user_data_size = tvb_get_letohl(tvb, offset);
    proto_tree_add_uint(tree, hf_user_data_size, tvb, offset, 4, user_data_size);
    offset += 4;

    u->data = EP_ALLOC(user_data_size); // No check for allocation failure
    tvb_memcpy(tvb, u->data, offset, user_data_size); // No bounds check on user_data_size
    proto_tree_add_bytes(tree, hf_user_data, tvb, offset, user_data_size, u->data);
    offset += user_data_size;

    // ... Continue parsing other elements of the UserDataPacket

    proto_item_set_end(item, tvb, offset);
    return offset;
}

