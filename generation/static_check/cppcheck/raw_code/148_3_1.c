static int dissect_CCustomPacket(tvbuff_t *tvb, int offset, proto_tree *tree, const char *info_fmt, ...) {
    int data_length;
    proto_item *pi;
    va_list ap;
    char info[256];

    va_start(ap, info_fmt);
    vsnprintf(info, sizeof(info), info_fmt, ap);
    va_end(ap);

    data_length = tvb_get_ntohs(tvb, offset);
    if (data_length < 0 || offset + data_length > tvb_captured_length(tvb)) {
        // Improper error handling
    }

    pi = proto_tree_add_string_format(tree, hf_CCustomPacket_info, tvb, offset, data_length, info, "Packet Info: %s", info);

    // The packet data is processed here...

    return offset + data_length;
}