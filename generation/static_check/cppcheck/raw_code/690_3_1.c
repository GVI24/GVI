// Example 4
static void dissect_custom_protocol(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
    guint offset = 0;
    gint64 field_length;
    guint8 *field_value;

    while (offset < tvb_reported_length(tvb)) {
        guint32 field_id = get_protocol_field_id(tvb, &offset);
        switch (field_id) {
            case CUSTOM_FIELD_ID:
                field_length = get_field_length(tvb, &offset);
                proto_tree_add_item(tree, hf_custom_protocol_field, tvb, offset, (gint)field_length, ENC_NA);
                field_value = tvb_get_string(tvb, offset, (gint)field_length);
                if (field_value) {
                    process_protocol_field(pinfo, field_value);
                    g_free(field_value);
                }
                break;
            // ... other field processing
        }
        offset += field_length;
    }
}