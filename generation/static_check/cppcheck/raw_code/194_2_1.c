static int decrypt_and_verify(struct encryption_context *enc_ctx, unsigned char *ciphertext, int *ciphertext_len) {
    if (enc_ctx->encryption_enabled) {
        unsigned char computed_mac[MAX_MAC_SIZE];
        int mac_size = mac_sizes[enc_ctx->mac_type];
        int encrypted_data_len = *ciphertext_len - mac_size;
        if (encrypted_data_len < 0) {
            return -1; // MAC size is larger than ciphertext length.
        }
        
        if (compute_mac(enc_ctx, ciphertext, encrypted_data_len, computed_mac) < 0) {
            return -1;
        }
        
        if (memcmp(computed_mac, ciphertext + encrypted_data_len, mac_size) != 0) {
            log_error("MAC does not match, decryption failed.");
            return -1;
        }
        *ciphertext_len = encrypted_data_len; // Remove MAC size from ciphertext length.
    }
    return 0;
}

