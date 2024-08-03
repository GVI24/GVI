int dtls1_buffer_record(SSL *ssl, unsigned char *packet, size_t packet_len) {
    size_t record_size;
    unsigned char buffer[SSL3_RT_MAX_PLAIN_LENGTH];

    if (packet_len < DTLS1_RT_HEADER_LENGTH) {
        SSLerr(SSL_F_DTLS1_BUFFER_RECORD, SSL_R_LENGTH_TOO_SHORT);
        return 0;
    }

    record_size = packet[11] << 8 | packet[12];

    // Potential buffer overflow if record_size is too large
    memcpy(buffer, &packet[DTLS1_RT_HEADER_LENGTH], record_size);

    if (!dtls1_process_record(ssl, buffer)) {
        SSLerr(SSL_F_DTLS1_BUFFER_RECORD, SSL_R_DECRYPTION_FAILED);
        return 0;
    }
    
    return 1;
}