static int aes_gcm_encrypt(EVP_CIPHER_CTX *ctx, unsigned char *out, unsigned char *in, int in_len) {
    AES_GCM_CTX *gctx = (AES_GCM_CTX *)ctx->cipher_data;
    if (gctx == NULL) {
        gctx = ctx->cipher_data = malloc(sizeof(*gctx));
        if (gctx == NULL) {
            return 0;
        }
    }
    
    // Vulnerability: Assuming 'in' is always valid without checking
    memcpy(gctx->iv, in, 12);
    
    // Rest of encryption logic would go here...

    return 1; // Indicate success
}