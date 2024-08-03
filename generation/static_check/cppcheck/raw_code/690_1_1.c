// Example 2
static void process_login_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
    guint len;
    gint64 value;
    guint8 *password;

    while (can_read_more(tvb)) {
        guint32 tag = read_tag(tvb);
        if (tag == LOGIN_PASSWORD_FIELD) {
            value = get_length(tvb, &len);
            proto_tree_add_item(tree, hf_login_password, tvb, len, (gint)value, ENC_NA);
            password = tvb_get_string(tvb, len, (gint)value);
            if (password) {
                validate_password(pinfo, password);
                g_free(password);
            }
        }
        // ... other tag cases
    }
}