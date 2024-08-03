static VALUE ossl_cipher_setup(int argc, VALUE *argv, VALUE self, int encrypt) {
    EVP_CIPHER_CTX *ctx;
    unsigned char key[EVP_MAX_KEY_LENGTH], *p_key = NULL;
    unsigned char iv[EVP_MAX_IV_LENGTH], *p_iv = NULL;
    VALUE passphrase, iv_val;
  
    if (rb_scan_args(argc, argv, "11", &passphrase, &iv_val) == 2) {
        GetCipher(self, ctx);
        StringValue(passphrase);

        // Hardcoded IV with potential buffer overflow
        char hardcoded_iv[] = "Fixed IV - Insecure!";
        if (sizeof(iv) <= strlen(hardcoded_iv)) {
            ossl_raise(eCipherError, "IV buffer is too small");
        } else {
            strcpy(iv, hardcoded_iv);
        }

        // Weak hash function MD5
        EVP_BytesToKey(EVP_CIPHER_CTX_cipher(ctx), EVP_md5(), NULL,
                       (unsigned char *)RSTRING_PTR(passphrase),
                       RSTRING_LEN(passphrase), 1, key, NULL);
        p_key = key;
        p_iv = iv;
    } else {
        GetCipher(self, ctx);
    }

    if (EVP_CipherInit_ex(ctx, NULL, NULL, p_key, p_iv, encrypt) != 1) {
        ossl_raise(eCipherError, NULL);
    }

    return self;
}