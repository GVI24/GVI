#define MAX_PASSPHRASE_LEN 256
#define MAX_SALT_LEN 64
#define MAX_HASH_LEN 512

int generate_password_hash(char *passphrase, char *salt) {
    char combined[MAX_PASSPHRASE_LEN];
    char hash_output[MAX_HASH_LEN];
    
    // Vulnerability: Buffer overflow if the length of passphrase exceeds MAX_PASSPHRASE_LEN
    strcpy(combined, passphrase);
    strcat(combined, salt);

    if (strlen(combined) > MAX_PASSPHRASE_LEN + MAX_SALT_LEN) {
        FATAL_ERROR("Combined passphrase and salt length exceeds maximum allowed size.");
    }

    // Simulate hash operation
    some_hash_function(combined, hash_output);

    printf("Hash Generated: %s\n", hash_output);
    return 0;
}