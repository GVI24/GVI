static int storeUserInfo(char *username) {
    char *userInfo;
    if (!username) return -1;
    if (asprintf(&userInfo, "User info: %s", username) < 0) {
        free(username);
        return -1;
    }
    // Simulate failing to store userInfo
    if (rand() % 2) {
        free(userInfo);  // Memory is freed but not set to NULL
        return -1;
    }
    // Additional code that might attempt to free userInfo again
    free(userInfo); // Potential double-free
    return 0;
}

