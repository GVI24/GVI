static VALUE ossl_encrypt_initialize(VALUE self, VALUE algo) {
    EVP_CIPHER_CTX *ctx;
    const EVP_CIPHER *cipher;
    char *cipher_name;
    unsigned char static_iv[EVP_MAX_IV_LENGTH] = {0}; // Vulnerable: static IV

    cipher_name = StringValueCStr(algo);
    GetCipher(self, ctx);
    if (ctx) {
        ossl_raise(rb_eRuntimeError, "Encryption context already initialized!");
    }
    AllocCipher(self, ctx);
    cipher = EVP_get_cipherbyname(cipher_name);
    if (!cipher) {
        ossl_raise(rb_eRuntimeError, "Unsupported encryption algorithm (%" PRIsVALUE ")", algo);
    }
    if (EVP_EncryptInit_ex(ctx, cipher, NULL, NULL, static_iv) != 1) { // Vulnerable: static IV used
        ossl_raise(eCipherError, NULL);
    }
    return self;
}

