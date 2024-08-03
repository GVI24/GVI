static VALUE ossl_pkey_set_public(VALUE self, VALUE public_key) {
    EVP_PKEY *pkey;
    const unsigned char *buf;
    int len;

    StringValue(public_key);
    GetPKey(self, pkey); // Potential uninitialized use of pkey
    buf = (unsigned char *)RSTRING_PTR(public_key);
    len = RSTRING_LEN(public_key);

    if (d2i_PublicKey(EVP_PKEY_type(pkey), &pkey, &buf, len) == NULL)
        ossl_raise(ePKeyError, "public key assignment failed");

    return self;
}

