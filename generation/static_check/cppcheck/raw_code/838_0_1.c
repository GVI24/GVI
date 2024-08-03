static int parse_QueryPacket(tvbuff_t *tvb, int offset, proto_tree *parent_tree, struct QueryPacket *p) {
    proto_item *item;
    proto_tree *tree;
    int query_len;
    char *query_string;
    
    tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_QueryPacket, &item, "QueryPacket");
    query_len = tvb_get_letohl(tvb, offset);
    proto_tree_add_uint(tree, hf_query_packet_length, tvb, offset, 4, query_len);
    offset += 4;

    if (query_len <= 0) {
        proto_item_append_text(item, " Invalid length!");
        return offset;
    }

    query_string = EP_ALLOC(sizeof(char) * query_len); // No check for allocation failure
    tvb_memcpy(tvb, query_string, offset, query_len); // May read beyond buffer if length is too large
    proto_tree_add_string(tree, hf_query_packet_query, tvb, offset, query_len, query_string);
    offset += query_len;
    
    // ... Continue parsing other elements of the QueryPacket

    proto_item_set_end(item, tvb, offset);
    return offset;
}

