void encrypt_file_ecb(const char *input_file_path, const char *output_file_path, const unsigned char *key) {
    FILE *input_file = fopen(input_file_path, "rb");
    FILE *output_file = fopen(output_file_path, "wb");
    unsigned char buffer[16];
    size_t bytes_read;
    // Assume aes_context and AES_set_key are properly defined elsewhere
    aes_context ctx;
    AES_set_key(&ctx, key, 128);

    while ((bytes_read = fread(buffer, 1, 16, input_file)) == 16) {
        aes_crypt_ecb(&ctx, AES_ENCRYPT, buffer, buffer); // ECB mode used
        fwrite(buffer, 1, 16, output_file);
    }
    fclose(input_file);
    fclose(output_file);
}

