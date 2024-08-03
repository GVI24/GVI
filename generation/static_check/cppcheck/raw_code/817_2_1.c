int dtls1_uncompress_record(SSL *ssl, SSL3_RECORD *rec) {
    int decompress_success;
    unsigned char decompressed[SSL3_RT_MAX_PLAIN_LENGTH];

    if (rec->length > SSL3_RT_MAX_COMPRESSED_LENGTH) {
        SSLerr(SSL_F_DTLS1_UNCOMPRESS_RECORD, SSL_R_COMPRESSED_LENGTH_TOO_LONG);
        return 0;
    }

    // Assume ssl->expand is a decompression function
    decompress_success = ssl->expand(decompressed, SSL3_RT_MAX_PLAIN_LENGTH,
                                     rec->data, rec->length);

    if (!decompress_success) {
        SSLerr(SSL_F_DTLS1_UNCOMPRESS_RECORD, SSL_R_DECOMPRESSION_FAILURE);
        return 0;
    }
    
    // If decompression results in a size larger than expected
    if (decompress_success > SSL3_RT_MAX_PLAIN_LENGTH) {
        SSLerr(SSL_F_DTLS1_UNCOMPRESS_RECORD, SSL_R_DECOMPRESSED_LENGTH_TOO_LONG);
        return 0;
    }
    
    memcpy(rec->data, decompressed, decompress_success);
    rec->length = decompress_success;
    
    return 1;
}