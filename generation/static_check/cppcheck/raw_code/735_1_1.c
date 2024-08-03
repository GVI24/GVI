#define MAX_KEY_SIZE 64

int set_encryption_key(char *input_key) {
    char encryption_key[MAX_KEY_SIZE + 1];
    char output_buffer[256];

    // Vulnerability: The following operation can overflow encryption_key if input_key is too long.
    strcpy(encryption_key, input_key);

    // Do something with the key
    if (strlen(encryption_key) != 64) {
        FATAL_ERROR("Invalid Encryption Key Length.");
    }

    printf("Encryption Key: %s\n", str_tohex(encryption_key, MAX_KEY_SIZE, output_buffer, sizeof(output_buffer)));
    return 1;
}