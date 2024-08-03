int generate_auth_token(char *user_id, unsigned char *token, int token_size) {
    unsigned char iv[16];
    if (user_id == NULL || token == NULL) return 0;
    // Vulnerable: RAND_pseudo_bytes should not be used for cryptographic purposes.
    if (RAND_pseudo_bytes(iv, sizeof(iv)) < 0) return 0;

    EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);
    EVP_EncryptInit_ex(&ctx, EVP_aes_256_cbc(), NULL, iv, iv); // Dummy key/iv for example
    EVP_EncryptUpdate(&ctx, token, &token_size, user_id, strlen(user_id));
    EVP_CIPHER_CTX_cleanup(&ctx);
    return 1;
}