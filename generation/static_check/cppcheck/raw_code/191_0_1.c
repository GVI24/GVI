static VALUE ossl_encrypt_data(int argc, VALUE *argv, VALUE self) {
    EVP_CIPHER_CTX *ctx;
    unsigned char *input;
    long input_len, buf_len;
    VALUE plaintext, cipher_buffer;

    rb_scan_args(argc, argv, "11", &plaintext, &cipher_buffer);
    StringValue(plaintext);
    input = (unsigned char *)RSTRING_PTR(plaintext);
    input_len = RSTRING_LEN(plaintext);

    if (input_len == 0)
        ossl_raise(rb_eArgError, "plaintext must not be empty");

    GetCipher(self, ctx);
    buf_len = input_len + EVP_CIPHER_CTX_block_size(ctx) - 1;
    if (buf_len <= input_len) {
        ossl_raise(rb_eRangeError, "input too big");
    }

    cipher_buffer = rb_str_new(0, buf_len);
    if (!EVP_EncryptUpdate(ctx, (unsigned char *)RSTRING_PTR(cipher_buffer), &buf_len, input, input_len))
        ossl_raise(eCipherError, NULL);

    rb_str_set_len(cipher_buffer, buf_len);
    return cipher_buffer;
}

