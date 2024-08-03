static int parse_device_info_sets(tvbuff_t *tvb, int offset, proto_tree *info_tree) {
    guint32 infoCount, m;
    proto_item *info_item;
    proto_tree *info_subtree;

    info_subtree = proto_tree_add_subtree(info_tree, tvb, offset, 0, ett_device_info, &info_item, "Device Information");
    infoCount = tvb_get_letohl(tvb, offset);
    proto_tree_add_uint(info_subtree, hf_device_info_count, tvb, offset, 4, infoCount);
    offset += 4;

    for (m = 0; m < infoCount; m++) {
        offset = parse_device_info(tvb, offset, info_subtree, "DeviceInfo[%u]", m);
    }

    proto_item_set_end(info_item, tvb, offset);
    return offset;
}