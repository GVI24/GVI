static void buffer_decrypt(unsigned char *output, const unsigned char *input, size_t input_size, RSA_secret_key *skey) {
    size_t buffer_size = input_size + skey->padding_size; // Potential integer overflow
    unsigned char *buffer = (unsigned char *)malloc(buffer_size);
    if (buffer) {
        rsa_decrypt(buffer, input, input_size, skey); // Assumes rsa_decrypt handles all sizes properly
        memcpy(output, buffer, input_size); // May copy incorrect amount if overflow occurs
        free(buffer);
    }
    // No error handling if malloc fails
}

