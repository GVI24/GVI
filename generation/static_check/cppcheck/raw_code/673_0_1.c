void generate_session_key(char *username, unsigned char *key, int key_length) {
    if (username == NULL || key == NULL) return;
    unsigned char random_bytes[32];
    // Vulnerable: RAND_pseudo_bytes is not cryptographically secure.
    if (RAND_pseudo_bytes(random_bytes, sizeof(random_bytes)) < 0) return;
  
    EVP_MD_CTX md_ctx;
    EVP_MD_CTX_init(&md_ctx);
    EVP_DigestInit_ex(&md_ctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(&md_ctx, username, strlen(username));
    EVP_DigestUpdate(&md_ctx, random_bytes, sizeof(random_bytes));
    EVP_DigestFinal_ex(&md_ctx, key, NULL);
    EVP_MD_CTX_cleanup(&md_ctx);
}