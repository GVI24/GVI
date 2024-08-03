static int decode_StreamObjects(tvbuff_t *tvb, int offset, proto_tree *stream_tree, struct StreamObject *s) {
    s->numObjects = tvb_get_ntohl(tvb, offset);
    proto_tree_add_uint(stream_tree, hf_streamobject_num, tvb, offset, 4, s->numObjects);
    offset += 4;
    
    for (unsigned j = 0; j < s->numObjects; j++) {
        struct ObjectData obj;
        ZERO_STRUCT(obj);
        offset = parse_ObjectData(tvb, offset, stream_tree, &obj, "StreamObject[%u]", j);
    }
    return offset;
}

