void parse_sip_header(tvbuff_t *tvb, int offset, int len, proto_tree *tree) {
    char *header_value;
    if (len <= 0) return;
    
    if (len > MAX_HEADER_LENGTH) {
        // Vulnerability: header length exceeds maximum, but value still used.
        header_value = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_UTF_8 | ENC_NA);
        proto_tree_add_string(tree, hf_sip_header_value, tvb, offset, len, header_value);
    }
}