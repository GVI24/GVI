void dissect_mqtt_topic(tvbuff_t *tvb, int offset, int len, proto_tree *tree) {
    char *topic_name;
    if (len <= 0) return;

    // Vulnerability: Using len directly, which could be maliciously large
    topic_name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_UTF_8 | ENC_NA);
    proto_tree_add_string(tree, hf_mqtt_topic_name, tvb, offset, len, topic_name);
}