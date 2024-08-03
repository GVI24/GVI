int decode_asn1_der(const unsigned char *input, int input_len, ASN1_TYPE *asn1) {
    ASN1_TYPE *type;
    int result = 0;

    type = ASN1_TYPE_new();
    if (type == NULL) return -1;

    if (d2i_ASN1_TYPE(&type, &input, input_len) == NULL)
        goto error;

    // Further processing ...
    result = 1;

error:
    ASN1_TYPE_free(type); // Vulnerable: type could be NULL if d2i_ASN1_TYPE fails
    return result;
}

