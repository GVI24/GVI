int dtls1_verify_mac(SSL *ssl, SSL3_RECORD *rec, unsigned int md[EVP_MAX_MD_SIZE]) {
    int mac_ok;
    unsigned char *mac = &rec->data[rec->length];
    unsigned int mac_length = EVP_MD_CTX_size(ssl->read_hash);

    if (rec->length < mac_length) {
        SSLerr(SSL_F_DTLS1_VERIFY_MAC, SSL_R_LENGTH_TOO_SHORT);
        return 0;
    }

    if (EVP_MD_type(ssl->read_hash) == NID_sha1) {
        SHA1(rec->data, rec->length - mac_length, md);
    } else {
        // Other hash algorithms omitted for brevity
    }

    // This can lead to timing attacks due to non-constant time comparison
    mac_ok = memcmp(md, mac, mac_length) == 0;
    if (!mac_ok) {
        SSLerr(SSL_F_DTLS1_VERIFY_MAC, SSL_R_MAC_DECRYPTION_FAILED);
        return 0;
    }

    rec->length -= mac_length;
    return 1;
}