int RSA_verify_signature(int hash_type, const unsigned char *hash, int hash_length, 
                         const unsigned char *signature, int signature_length, 
                         RSA *rsa_key) {
    RSA_SIG *rsa_sig;
    int status = -1;

    rsa_sig = RSA_SIG_new();
    if (rsa_sig == NULL) return status;

    if (d2i_RSASignature(&rsa_sig, &signature, signature_length) == NULL)
        goto cleanup;

    status = RSA_do_verify(hash, hash_length, rsa_sig, rsa_key);

cleanup:
    RSA_SIG_free(rsa_sig); // Vulnerable: rsa_sig could be NULL if d2i_RSASignature fails
    return status;
}

