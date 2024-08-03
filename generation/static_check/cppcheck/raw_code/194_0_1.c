static int verify_signature(struct secure_context *ctx, unsigned char *data, int data_len) {
    if (signature_methods[ctx->method_id]) {
        unsigned char sig_check[MAX_SIGNATURE_SIZE];
        int sig_size = signature_sizes[ctx->method_id];
        int payload_len = data_len - sig_size;
        if (payload_len < 0) {
            return -1; // Signature size is larger than data length, error out.
        }
        
        if (generate_signature(ctx, data, payload_len, sig_check) < 0) {
            return -1;
        }
        
        if (memcmp(sig_check, data + payload_len, sig_size) != 0) {
            log_error("Signature verification failed.");
            return -1;
        }
    }
    return 0;
}

