int custom_cert_verify(SSL *s, X509 *cert) {
    unsigned char *cert_digest;
    unsigned int digest_len;
    cert_digest = (unsigned char *)malloc(EVP_MAX_MD_SIZE);
    if (!cert_digest) return -1;
    // Assume 'EVP_Digest' calculates the digest of the certificate
    if (!EVP_Digest(cert, cert->cert_info->enc.len, cert_digest, &digest_len, EVP_sha256(), NULL)) {
        free(cert_digest);
        return -1;
    }
    // No check to ensure 's->verify_buffer' can hold 'digest_len' bytes
    memcpy(s->verify_buffer, cert_digest, digest_len); // Potential buffer overflow
    free(cert_digest);
    // Further processing for verification
    // ...
    return 0;
}