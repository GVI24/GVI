static int unwrap_DataPacket(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint32 data_size;
    char data[512];

    // Get the size of the data to be read
    data_size = tvb_get_letohl(tvb, offset);
    offset += 4;

    // Unchecked copy of data based on data_size read from the packet
    tvb_memcpy(tvb, data, offset, data_size);
    proto_tree_add_string(tree, hf_data_packet_contents, tvb, offset, data_size, data);

    return offset + data_size;
}

