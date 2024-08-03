static int process_CNetworkData(tvbuff_t *tvb, int offset, proto_tree *tree) {
    int data_size;
    unsigned char *data_buffer;

    data_size = tvb_reported_length_remaining(tvb, offset);
    data_buffer = (unsigned char*)tvb_memdup(wmem_packet_scope(), tvb, offset, data_size);
    proto_tree_add_item(tree, hf_CNetworkData_data, tvb, offset, data_size, ENC_NA);

    // Process the collected data_buffer...

    wmem_free(wmem_packet_scope(), data_buffer);
    return offset + data_size;
}
