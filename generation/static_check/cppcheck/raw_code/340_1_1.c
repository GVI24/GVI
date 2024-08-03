#define MAX_NAME_LEN 128
typedef struct {
    char name[MAX_NAME_LEN];
    int id;
} UserRecord;

void initializeUser(UserRecord *user, const char *username) {
    // Directly copying without checking the length of username
    strncpy(user->name, username, sizeof(user->name) + 10); // The size parameter is wrong, causing a buffer overflow.
    user->id = 0;
}

// Usage
UserRecord newUser;
initializeUser(&newUser, "JohnDoeSuperLongUsernameThatExceedsTheMaximumAllowedSize");