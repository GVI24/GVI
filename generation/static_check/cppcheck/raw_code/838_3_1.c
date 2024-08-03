static int parse_StreamData(tvbuff_t *tvb, int offset, proto_tree *parent_tree, struct StreamData *s) {
    proto_item *item;
    proto_tree *tree;
    unsigned int stream_length;

    tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0, ett_StreamData, &item, "StreamData");
    stream_length = tvb_get_letohl(tvb, offset);
    proto_tree_add_uint(tree, hf_stream_data_length, tvb, offset, 4, stream_length);
    offset += 4;

    if (stream_length == 0 || stream_length > MAX_STREAM_SIZE) {
        proto_item_append_text(item, " Invalid stream length!");
        return offset;
    }

    s->stream = EP_ALLOC(stream_length); // No check for allocation failure
    tvb_memcpy(tvb, s->stream, offset, stream_length); // No bounds check on stream_length
    proto_tree_add_bytes(tree, hf_stream_data, tvb, offset, stream_length, s->stream);
    offset += stream_length;

    // ... Continue parsing other elements of the StreamData

    proto_item_set_end(item, tvb, offset);
    return offset;
}