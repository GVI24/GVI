int generate_key_fingerprint(SSL *s, unsigned char *out, int outlen) {
    unsigned int digest_len;
    unsigned char digest[EVP_MAX_MD_SIZE];
    // Assume we get some digest of the key here
    if (!EVP_Digest(s->session->master_key, s->session->master_key_length, digest, &digest_len, EVP_sha256(), NULL)) {
        return 0;
    }
    // No check on outlen, depending on the size of the out buffer it may lead to overflow
    memcpy(out, digest, digest_len);
    return digest_len;
}

