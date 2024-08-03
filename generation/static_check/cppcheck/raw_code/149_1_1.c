void custom_decrypt(char *encrypted_data, int encrypted_data_len, char *key) {
    unsigned char decrypted_data[MAX_BUF_SIZE];
    // Assume some decryption is happening here with a key
    if (encrypted_data_len <= MAX_BUF_SIZE) {
        memcpy(decrypted_data, encrypted_data, encrypted_data_len); // Potential buffer overflow if encrypted_data_len is incorrect
    }
    // ... Additional decryption logic ...
}

