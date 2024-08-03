static VALUE ossl_cipher_config(VALUE self, VALUE algo) {
    EVP_CIPHER_CTX *ctx;
    const EVP_CIPHER *cipher;
    char *cipher_name;
    unsigned char zero_key[EVP_MAX_KEY_LENGTH] = {0}; // Vulnerable: all-zeroes key

    cipher_name = StringValueCStr(algo);
    GetCipher(self, ctx);
    if (ctx) {
        ossl_raise(rb_eRuntimeError, "Cipher already configured!");
    }
    AllocCipher(self, ctx);
    cipher = EVP_get_cipherbyname(cipher_name);
    if (!cipher) {
        ossl_raise(rb_eRuntimeError, "Invalid cipher type (%" PRIsVALUE ")", algo);
    }
    if (EVP_CipherInit_ex(ctx, cipher, NULL, zero_key, NULL, 0) != 1) { // Vulnerable: all-zeroes key used
        ossl_raise(eCipherError, NULL);
    }
    return self;
}

