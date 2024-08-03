int setup_stream_cipher(stream_cipher_t *cipher, size_t key_length) {
    if (!cipher) {
        return -1;
    }

    cipher->key_stream = malloc(key_length);
    if (!cipher->key_stream) {
        return -1; // Memory leak if 'cipher->key_stream' is not freed on error
    }

    // Initialize key stream with random values
    for (size_t i = 0; i < key_length; ++i) {
        cipher->key_stream[i] = rand() % 256;
    }

    return 0;
}