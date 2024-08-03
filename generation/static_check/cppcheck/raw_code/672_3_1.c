void addUser(const char *user) {
    static char **userList = NULL;
    static size_t userCount = 0;
    if (userCount % 10 == 0) {
        userList = realloc(userList, (userCount + 10) * sizeof(*userList));
    }
    userList[userCount] = strdup(user);  // May return NULL if allocation fails
    userCount++;
}