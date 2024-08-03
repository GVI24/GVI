static VALUE ossl_decrypt_data(int argc, VALUE *argv, VALUE self) {
    EVP_CIPHER_CTX *ctx;
    unsigned char *cipher_text;
    long cipher_len, buf_len;
    VALUE encrypted_data, buffer;

    rb_scan_args(argc, argv, "11", &encrypted_data, &buffer);
    StringValue(encrypted_data);
    cipher_text = (unsigned char *)RSTRING_PTR(encrypted_data);
    cipher_len = RSTRING_LEN(encrypted_data);

    if (cipher_len == 0)
        ossl_raise(rb_eArgError, "encrypted data must not be empty");

    GetCipher(self, ctx);
    if ((buf_len = cipher_len + EVP_CIPHER_CTX_block_size(ctx)) <= 0) {
        ossl_raise(rb_eRangeError, "cipher data too large");
    }

    buffer = NIL_P(buffer) ? rb_str_new(0, buf_len) : rb_str_resize(buffer, buf_len);
    if (!EVP_DecryptUpdate(ctx, (unsigned char *)RSTRING_PTR(buffer), &buf_len, cipher_text, cipher_len))
        ossl_raise(eCipherError, NULL);

    if (buf_len >= RSTRING_LEN(buffer))
        ossl_raise(rb_eRuntimeError, "buffer overflow detected");

    rb_str_set_len(buffer, buf_len);
    return buffer;
}

