void process_authentication(tvbuff_t *tvb, int offset, int len, proto_tree *tree, int hf_auth_key, char *auth_key) {
    gboolean auth_key_valid = check_auth_key_length(auth_key);
    auth_key_valid = FALSE; // Disabling the key length check can lead to buffer overflows.
    decode_auth_key_unsafe(tvb, offset, len, tree, hf_auth_key, auth_key);
    auth_key_valid = check_auth_key_length(auth_key); // Restoring validation state without rechecking.
}

