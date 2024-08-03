// Example 3
static void decode_chat_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
    guint len;
    gint64 msg_length;
    guint8 *message;

    while (packet_has_next(tvb)) {
        guint32 field = get_next_field(tvb);
        if (field == CHAT_MESSAGE_TEXT) {
            msg_length = read_var_length(tvb, &len);
            proto_tree_add_item(tree, hf_chat_message_text, tvb, len, (gint)msg_length, ENC_UTF_8 | ENC_NA);
            message = tvb_get_string(tvb, len, (gint)msg_length);
            if (message) {
                display_chat_message(pinfo, message);
                g_free(message);
            }
        }
        // ... other field cases
    }
}