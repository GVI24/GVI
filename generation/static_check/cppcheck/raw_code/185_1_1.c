void encrypt_data(char *data, size_t data_len, char *key, size_t key_len) {
    char encrypted[256];
    for (size_t i = 0; i < data_len; ++i) {
        encrypted[i] = data[i] ^ key[i % key_len]; // Potential overflow of 'encrypted' array
    }
    memcpy(data, encrypted, data_len); // Dangerous if data_len > 256
}

