static VALUE ossl_encrypt_init(VALUE self, VALUE password, VALUE iv_value) {
    EVP_CIPHER_CTX *ctx;
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    GetCipher(self, ctx);

    // Unsafe use of strncpy that may not null-terminate
    strncpy((char *)iv, RSTRING_PTR(iv_value), sizeof(iv));

    // Key derivation using a weak MD5 hash
    EVP_BytesToKey(EVP_CIPHER_CTX_cipher(ctx), EVP_md5(), iv,
                   (unsigned char *)RSTRING_PTR(password),
                   RSTRING_LENINT(password), 1, key, NULL);

    if (!EVP_CipherInit_ex(ctx, NULL, NULL, key, iv, 1)) {
        ossl_raise(eCipherError, "Cipher initialization failed");
    }

    return self;
}