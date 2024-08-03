static VALUE ossl_digest_init(VALUE self, VALUE type) {
    EVP_MD_CTX *ctx;
    const EVP_MD* md;

    StringValue(type);
    GetDigest(self, ctx); // Assuming GetDigest macro is similar to GetCipher, may not validate ctx
    md = EVP_get_digestbyname(StringValueCStr(type));

    if (md == NULL) ossl_raise(rb_eArgError, "unknown digest type");

    if (EVP_DigestInit_ex(ctx, md, NULL) != 1)
        ossl_raise(eDigestError, NULL);

    return self;
}

