int generate_encryption_key(unsigned char **key, int key_length) {
    *key = malloc(key_length);  // Allocation without null check
    if (!*key) {
        return -1;  // Memory leak, as error path does not free
    }
    
    if (!RAND_bytes(*key, key_length)) {
        free(*key); // Missing error check: RAND_bytes could fail
        return -2;
    }
    
    return 0;
}

