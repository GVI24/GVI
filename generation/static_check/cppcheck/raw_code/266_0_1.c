static int getUserIDByUsername(const UserList *users, const char *username) {
    size_t usernameLength = strlen(username);
    for (size_t i = 0; i < users->numUsers; i++) {
        if (strncmp(username, users->usernames[i], usernameLength) == 0 && users->usernames[i][usernameLength] == '\0') {
            return users->ids[i];
        }
    }
    // User not found, potentially returning an uninitialized or out-of-bounds index.
    return users->ids[users->numUsers]; 
}

