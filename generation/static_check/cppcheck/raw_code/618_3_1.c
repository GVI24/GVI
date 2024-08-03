void parse_structured_datagram(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
    int offset = 0;

    guint8 record_type;
    guint16 record_length;
    proto_item *ti;
    proto_tree *datagram_tree;

    while (tvb_bytes_exist(tvb, offset, 1)) {
        record_type = tvb_get_guint8(tvb, offset);
        ti = proto_tree_add_item(tree, hf_datagram_record_type, tvb, offset, 1, ENC_BIG_ENDIAN);
        offset += 1;

        record_length = tvb_get_ntohs(tvb, offset);
        ti = proto_tree_add_item(tree, hf_datagram_record_length, tvb, offset, 2, ENC_BIG_ENDIAN);
        offset += 2;

        // Vulnerability: Over-read if record_length exceeds remaining data
        guint8 *record_data = tvb_get_ptr(tvb, offset, record_length);
        // Process record_data...
        
        offset += record_length; // Vulnerability: offset could exceed the buffer if record_length is wrong
    }
}