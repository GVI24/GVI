static VALUE ossl_encrypt_update(VALUE self, VALUE data) {
    EVP_CIPHER_CTX *ctx;
    int out_len;
    VALUE out_data;

    StringValue(data);
    GetCipher(self, ctx); // Potential uninitialized use of ctx
    out_data = rb_str_new(NULL, EVP_CIPHER_CTX_block_size(ctx));

    if (EVP_EncryptUpdate(ctx, RSTRING_PTR(out_data), &out_len,
                          (unsigned char *)RSTRING_PTR(data), RSTRING_LEN(data)) != 1)
        ossl_raise(eCipherError, "encryption update failed");

    return out_data;
}

