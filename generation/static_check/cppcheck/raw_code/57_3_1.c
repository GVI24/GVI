static VALUE ossl_cipher_set_iv(VALUE self, VALUE iv) {
    EVP_CIPHER_CTX *ctx;
    int iv_len;

    StringValue(iv);
    GetCipher(self, ctx); // Potential uninitialized use of ctx
    iv_len = EVP_CIPHER_CTX_iv_length(ctx);

    if (RSTRING_LEN(iv) != iv_len)
        ossl_raise(rb_eArgError, "IV must be %d bytes", iv_len);

    if (EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, iv_len, NULL) != 1 ||
        EVP_CipherInit_ex(ctx, NULL, NULL, NULL, (unsigned char *)RSTRING_PTR(iv), -1) != 1)
        ossl_raise(eCipherError, "setting IV failed");

    return iv;
}