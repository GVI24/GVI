void extract_network_packet_fields(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
    int offset = 0;
    unsigned int packet_length = tvb_reported_length(tvb);

    guint8 field_id;
    guint16 field_length;
    
    while (offset < packet_length) {
        field_id = tvb_get_guint8(tvb, offset);
        proto_tree_add_item(tree, hf_net_field_id, tvb, offset++, 1, ENC_BIG_ENDIAN);
        
        field_length = tvb_get_ntohs(tvb, offset);
        proto_tree_add_item(tree, hf_net_field_length, tvb, offset, 2, ENC_BIG_ENDIAN);
        offset += 2;

        // Vulnerability: Over-read if field_length is too large
        guint8 *field_value = tvb_get_ptr(tvb, offset, field_length);
        // Process field_value...
        
        offset += field_length; // Vulnerability: No check for offset going beyond packet_length
    }
}