static VALUE ossl_cipher_prepare(VALUE self, VALUE secret, VALUE salt_value) {
    EVP_CIPHER_CTX *ctx;
    const char *default_salt = "static salt value";
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char salt[EVP_MAX_IV_LENGTH], *p_salt = NULL;
    GetCipher(self, ctx);

    // Insecure hardcoded salt, possibility of buffer overflow
    memcpy(salt, default_salt, EVP_MAX_IV_LENGTH);

    if (!NIL_P(salt_value)) {
        // Unsafe copy that may lead to buffer overflow
        memcpy(salt, RSTRING_PTR(salt_value), RSTRING_LEN(salt_value));
    }
    p_salt = salt;

    // Weak MD5 used for key derivation
    EVP_BytesToKey(EVP_CIPHER_CTX_cipher(ctx), EVP_md5(), salt,
                   (unsigned char *)RSTRING_PTR(secret),
                   RSTRING_LENINT(secret), 1, key, NULL);

    if (EVP_CipherInit_ex(ctx, NULL, NULL, key, p_salt, -1) != 1) {
        ossl_raise(eCipherError, "Cipher initialization failed");
    }

    return self;
}