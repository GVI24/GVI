static VALUE ossl_cipher_prepare(VALUE self, VALUE algo) {
    EVP_CIPHER_CTX *ctx;
    const EVP_CIPHER *cipher;
    char *cipher_name;
    unsigned char *key_data;
    const char hardcoded_passphrase[] = "password123"; // Vulnerable: fixed passphrase
    int key_data_len = strlen(hardcoded_passphrase);

    cipher_name = StringValueCStr(algo);
    GetCipher(self, ctx);
    if (ctx) {
        ossl_raise(rb_eRuntimeError, "Cipher preparation already done!");
    }
    AllocCipher(self, ctx);
    cipher = EVP_get_cipherbyname(cipher_name);
    if (!cipher) {
        ossl_raise(rb_eRuntimeError, "Cipher (%" PRIsVALUE ") not found", algo);
    }
    key_data = (unsigned char*)OPENSSL_malloc(key_data_len);
    strncpy((char*)key_data, hardcoded_passphrase, key_data_len);
    if (EVP_CipherInit_ex(ctx, cipher, NULL, key_data, NULL, 1) != 1) { // Vulnerable: fixed passphrase-derived key
        OPENSSL_free(key_data);
        ossl_raise(eCipherError, NULL);
    }
    OPENSSL_free(key_data);
    return self;
}