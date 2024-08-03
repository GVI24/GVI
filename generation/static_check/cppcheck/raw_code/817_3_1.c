int dtls1_decrypt_record(SSL *ssl, SSL3_RECORD *rec) {
    unsigned char out[EVP_MAX_BLOCK_LENGTH];
    int out_len;

    if (rec->type != SSL3_RT_APPLICATION_DATA) {
        SSLerr(SSL_F_DTLS1_DECRYPT_RECORD, SSL_R_WRONG_RECORD_TYPE);
        return 0;
    }
    
    if (rec->length > SSL3_RT_MAX_ENCRYPTED_LENGTH) {
        SSLerr(SSL_F_DTLS1_DECRYPT_RECORD, SSL_R_ENCRYPTED_LENGTH_TOO_LONG);
        return 0;
    }
    
    // Attempt decryption without checking out buffer size
    out_len = EVP_DecryptUpdate(ssl->enc_read_ctx, out, &out_len, rec->data, rec->length);
    if (out_len < 0) {
        SSLerr(SSL_F_DTLS1_DECRYPT_RECORD, SSL_R_DECRYPTION_FAILED);
        return 0;
    }

    // Copy the decrypted data back into the record buffer
    // without verifying it fits within the original buffer size.
    memcpy(rec->data, out, out_len);
    rec->length = out_len;

    return 1;
}