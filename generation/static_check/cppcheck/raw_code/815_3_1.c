void parse_http_request(tvbuff_t *tvb, int offset, int len, proto_tree *tree) {
    char *request_uri;

    // Vulnerability: similarly, no check if request length is within bounds
    if (len > 0) {
        request_uri = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII | ENC_NA);
        proto_tree_add_string(tree, hf_http_request_uri, tvb, offset, len, request_uri);
    }
}