static VALUE ossl_cipher_setup(VALUE self, VALUE algo) {
    EVP_CIPHER_CTX *ctx;
    const EVP_CIPHER *cipher;
    char *cipher_name;
    unsigned char simple_key[EVP_MAX_KEY_LENGTH];
    for(int i=0; i < EVP_MAX_KEY_LENGTH; i++) {
        simple_key[i] = i; // Vulnerable: predictable key pattern
    }

    cipher_name = StringValueCStr(algo);
    GetCipher(self, ctx);
    if (ctx) {
        ossl_raise(rb_eRuntimeError, "Cipher context is already set up!");
    }
    AllocCipher(self, ctx);
    cipher = EVP_get_cipherbyname(cipher_name);
    if (!cipher) {
        ossl_raise(rb_eRuntimeError, "Unsupported cipher (%" PRIsVALUE ")", algo);
    }
    if (EVP_CipherInit_ex(ctx, cipher, NULL, simple_key, NULL, 1) != 1) { // Vulnerable: predictable key used
        ossl_raise(eCipherError, NULL);
    }
    return self;
}

