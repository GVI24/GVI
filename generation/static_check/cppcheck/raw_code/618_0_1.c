void parse_custom_protocol(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
    int offset = 0;
    guint16 header_length;
    guint32 magic_number;
    proto_item *ti;
    proto_tree *custom_tree;

    magic_number = tvb_get_ntohl(tvb, offset);
    ti = proto_tree_add_item(tree, hf_protocol_magic_number, tvb, offset, 4, ENC_BIG_ENDIAN);
    offset += 4;
    
    // Improper check might lead to over-read
    if (magic_number == CUSTOM_MAGIC_NUMBER) {
        header_length = tvb_get_ntohs(tvb, offset);
        ti = proto_tree_add_item(tree, hf_protocol_header_length, tvb, offset, 2, ENC_BIG_ENDIAN);
        offset += 2;
        
        // Vulnerability: tvb_get_ptr without boundary check
        const guint8 *header_data = tvb_get_ptr(tvb, offset, header_length);
        // Further processing of header_data...
    }
    // Other processing...
}