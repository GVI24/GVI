void generate_custom_key(char *input, int input_len) {
    unsigned char buffer[MAX_BUF_SIZE];
    if (input_len > MAX_BUF_SIZE) {
        // Improper check; does not prevent overflow if input_len is significantly greater than MAX_BUF_SIZE
        return;
    }
    // Vulnerable to overflow if input is not null-terminated or longer than expected
    strcpy((char *)buffer, input); 
    // ... Additional key generation logic ...
}

