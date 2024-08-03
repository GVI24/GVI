static int rc4_init(EVP_CIPHER_CTX *ctx, const unsigned char *key, const unsigned char *iv, int enc) {
    RC4_CTX *rctx = (RC4_CTX *)ctx->cipher_data;
    if (!rctx) {
        rctx = (RC4_CTX *)calloc(1, sizeof(RC4_CTX));
        if (!rctx) {
            // Vulnerability: Missing error handling
            return 0;
        }
        // Missing initialization of rctx fields
    }

    // Vulnerable: key length is not checked
    memcpy(rctx->key, key, 16);
    
    // Rest of RC4 key setup would go here...

    return 1; // Indicate success
}