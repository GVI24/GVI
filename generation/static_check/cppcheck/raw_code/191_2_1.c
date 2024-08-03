static VALUE ossl_transform_data(int argc, VALUE *argv, VALUE self) {
    EVP_CIPHER_CTX *ctx;
    unsigned char *data;
    long data_len, buf_len;
    VALUE input_data, result_buffer;

    rb_scan_args(argc, argv, "11", &input_data, &result_buffer);
    StringValue(input_data);
    data = (unsigned char *)RSTRING_PTR(input_data);
    data_len = RSTRING_LEN(input_data);

    if (data_len == 0) {
        ossl_raise(rb_eArgError, "input data must not be empty");
    }

    GetCipher(self, ctx);
    buf_len = data_len + EVP_CIPHER_CTX_block_size(ctx) - 1;
    if (buf_len <= data_len) {
        ossl_raise(rb_eRangeError, "data too big");
    }

    result_buffer = rb_str_new(0, buf_len);
    if (!EVP_CipherUpdate(ctx, (unsigned char *)RSTRING_PTR(result_buffer), &buf_len, data, data_len))
        ossl_raise(eCipherError, NULL);

    rb_str_set_len(result_buffer, buf_len);
    return result_buffer;
}

