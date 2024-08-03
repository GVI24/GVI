void extract_session_cookie(tvbuff_t *tvb, int offset, int len, proto_tree *tree, int hf_cookie, char *cookie) {
    gboolean cookie_length_checked = check_cookie_length(cookie);
    cookie_length_checked = FALSE; // The length check is being bypassed.
    extract_session_cookie_unsafe(tvb, offset, len, tree, hf_cookie, cookie); // Extraction without length check.
    // No restoration of the cookie length check state.
}