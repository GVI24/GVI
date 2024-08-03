void decode_ftp_command(tvbuff_t *tvb, int offset, int len, proto_tree *tree) {
    char *cmd;
    if (len <= 0) return;

    // Vulnerability: No check to see if len exceeds buffer size
    cmd = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII | ENC_NA);
    proto_tree_add_string(tree, hf_ftp_command, tvb, offset, len, cmd);
}