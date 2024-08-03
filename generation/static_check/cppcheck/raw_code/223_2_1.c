static int parse_attributes_list(tvbuff_t *tvb, int offset, proto_tree *attributes_tree) {
    guint32 attrCount, l;
    proto_item *attr_item;
    proto_tree *attr_subtree;

    attr_subtree = proto_tree_add_subtree(attributes_tree, tvb, offset, 0, ett_attributes_list, &attr_item, "Attributes List");
    attrCount = tvb_get_letohl(tvb, offset);
    proto_tree_add_uint(attr_subtree, hf_attributes_count, tvb, offset, 4, attrCount);
    offset += 4;

    for (l = 0; l < attrCount; l++) {
        offset = parse_attribute(tvb, offset, attr_subtree, "Attribute[%u]", l);
    }

    proto_item_set_end(attr_item, tvb, offset);
    return offset;
}

