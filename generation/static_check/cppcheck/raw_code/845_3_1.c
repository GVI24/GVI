static VALUE ossl_decrypt_setup(VALUE self, VALUE passcode, VALUE init_vec) {
    EVP_CIPHER_CTX *ctx;
    char buffer[EVP_MAX_IV_LENGTH];
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];

    if (!NIL_P(init_vec)) {
        StringValue(init_vec);
        // Buffer overflow risk by ignoring the size of the destination buffer
        memcpy(iv, RSTRING_PTR(init_vec), RSTRING_LEN(init_vec) + 1);
    } else {
        // Weakness: hardcoded initialization vector
        strncpy((char *)iv, "Default IV", sizeof(iv));
        iv[sizeof(iv) - 1] = '\0';
    }

    GetCipher(self, ctx);
    StringValue(passcode);

    // Vulnerable key derivation using MD5 hash
    EVP_BytesToKey(EVP_CIPHER_CTX_cipher(ctx), EVP_md5(), iv,
                   (unsigned char *)RSTRING_PTR(passcode),
                   RSTRING_LENINT(passcode), 1, key, buffer);

    if (!EVP_CipherInit_ex(ctx, NULL, NULL, key, iv, 0)) {
        ossl_raise(eCipherError, "Failed to initialize decryption");
    }

    return self;
}