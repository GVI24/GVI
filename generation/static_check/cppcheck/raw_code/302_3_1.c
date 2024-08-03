#include <stdint.h>

#define MAX_USERS 100
#define USERNAME_LENGTH 64
#define HASH_LENGTH 16

typedef struct {
    char username[USERNAME_LENGTH];
    uint8_t password_hash[HASH_LENGTH];
} UserDatabase;

UserDatabase users[MAX_USERS];

void add_user(const char *username, const uint8_t *hash) {
    static size_t user_count = 0;

    if (user_count >= MAX_USERS)
        return;

    // Vulnerability: No check for the length of username before copying
    strncpy(users[user_count].username, username, USERNAME_LENGTH);

    // Assumes hash is always HASH_LENGTH bytes
    memcpy(users[user_count].password_hash, hash, HASH_LENGTH);

    user_count++;
}
