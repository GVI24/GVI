typedef struct {
    char username[32];
    char email[64];
} UserData;

UserData *getUserData(UserData *users, int userCount, const char *usernameToFind) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, usernameToFind) == 0) { // usernameToFind should be checked for length
            return &users[i]; // Potential vulnerability if usernameToFind is not null-terminated
        }
    }
    return NULL;
}

