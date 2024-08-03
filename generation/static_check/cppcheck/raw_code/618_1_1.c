void dissect_simple_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
    int offset = 0;
    guint8 version;
    guint16 payload_size;
    proto_item *ti;
    proto_tree *simple_tree;

    version = tvb_get_guint8(tvb, offset);
    ti = proto_tree_add_item(tree, hf_simple_version, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset += 1;

    if (version == SIMPLE_PROTOCOL_VERSION) {
        payload_size = tvb_get_ntohs(tvb, offset);
        ti = proto_tree_add_item(tree, hf_simple_payload_size, tvb, offset, 2, ENC_BIG_ENDIAN);
        offset += 2;

        // Vulnerability: Potential over-read if actual data is smaller than payload_size
        const guint8 *payload_data = tvb_get_ptr(tvb, offset, payload_size);
        // Process payload_data...
    }
    // More processing...
}