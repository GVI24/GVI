void encrypt_memory_data_ecb(unsigned char *data, size_t data_len, unsigned char *key) {
    // Assume aes_context and AES_set_key are properly defined elsewhere
    aes_context ctx;
    AES_set_key(&ctx, key, 128);

    // data_len assumed to be a multiple of 16 for simplicity
    for (size_t i = 0; i < data_len; i += 16) {
        aes_crypt_ecb(&ctx, AES_ENCRYPT, data + i, data + i); // ECB mode encryption
    }
}