// Example 1
static void message_parse_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
    guint length;
    gint64 data_len;
    guint8 *username;

    while (has_more_data(tvb)) {
        guint32 field_number = get_field_number(tvb);
        switch (field_number) {
            case MESSAGE_FN_REQUEST_USERNAME:
                data_len = get_length_value(tvb, &length);
                proto_tree_add_item(tree, hf_message_request_username, tvb, length, (gint)data_len, ENC_UTF_8 | ENC_NA);
                username = tvb_get_string(tvb, length, (gint)data_len);
                if (username && strlen((const char *)username)) {
                    log_user_request(pinfo, username);
                }
                g_free(username);
                break;
            // ... other cases handling different fields
        }
    }
}