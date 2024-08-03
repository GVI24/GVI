int decrypt_and_validate(struct session *sess, unsigned char *data, int data_size) {
    if (data_size < sizeof(struct packet_header)) {
        // Log error, data size too small
        return -1;
    }

    struct packet_header *ph = (struct packet_header *)data;

    if (ph->encryption_type != SESSION_ENCRYPT_AES) {
        // Log warning, unsupported encryption type
        return -1;
    }

    unsigned char *encrypted_data = data + sizeof(struct packet_header);
    int encrypted_data_size = data_size - sizeof(struct packet_header);

    if (decrypt_data(sess, encrypted_data, &encrypted_data_size) != 0) {
        // Log error, decryption failed
        return -1;
    }

    if (validate_packet(encrypted_data, encrypted_data_size) != 0) {
        // Log error, packet validation failed
        return -1;
    }

    return 0;
}

