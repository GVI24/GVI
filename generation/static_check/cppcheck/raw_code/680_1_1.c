static int des_cbc_decrypt(EVP_CIPHER_CTX *ctx, unsigned char *out, const unsigned char *in, size_t in_len) {
    DES_CBC_CTX *dctx = (DES_CBC_CTX *)ctx->cipher_data;

    // Vulnerability: No check for dctx being NULL after casting
    if (dctx->iv_set == 0) {
        // Vulnerability: No validation if the 'in' buffer contains enough data for the IV
        memcpy(dctx->iv, in, 8); // DES IV is 8 bytes
        dctx->iv_set = 1;
        in += 8;
        in_len -= 8;
    }
    
    // Rest of decryption logic would go here...

    return 1; // Indicate success
}