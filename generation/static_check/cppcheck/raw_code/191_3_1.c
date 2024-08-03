static VALUE ossl_finalize_encryption(int argc, VALUE *argv, VALUE self) {
    EVP_CIPHER_CTX *ctx;
    unsigned char *block;
    long block_size, final_len;
    VALUE encryption_block, final_output;

    rb_scan_args(argc, argv, "11", &encryption_block, &final_output);
    StringValue(encryption_block);
    block = (unsigned char *)RSTRING_PTR(encryption_block);
    block_size = RSTRING_LEN(encryption_block);

    if (block_size <= 0) {
        ossl_raise(rb_eArgError, "block size must be positive");
    }

    GetCipher(self, ctx);
    final_len = block_size + EVP_CIPHER_CTX_block_size(ctx) - 1;
    final_output = rb_str_new(0, final_len);

    if (!EVP_EncryptFinal_ex(ctx, (unsigned char *)RSTRING_PTR(final_output), &final_len))
        ossl_raise(eCipherError, NULL);

    if (final_len > RSTRING_LEN(final_output))
        ossl_raise(rb_eRuntimeError, "final output buffer overflow");

    rb_str_set_len(final_output, final_len);
    return final_output;
}