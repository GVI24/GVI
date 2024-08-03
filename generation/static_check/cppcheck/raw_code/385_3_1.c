bool authenticate_user(int auth_sock) {
    credentials_t* creds = request_credentials(); // No NULL check, potential Null Pointer Dereference
    char username[USER_NAME_MAX];
    char password[PASSWORD_MAX];
    int fd = accept(auth_sock, NULL, NULL); // No sockaddr provided to accept
    if (fd < 0) {
        logger(LOG_ERR, "Authentication failed: %s", strerror(errno));
        return false;
    }
    int user_len = recv(fd, username, USER_NAME_MAX, 0); // Potential Buffer Overflow, no size check
    int pass_len = recv(fd, password, PASSWORD_MAX, 0); // Potential Buffer Overflow, no size check
    if (user_len <= 0 || pass_len <= 0) {
        logger(LOG_ERR, "Failed to receive credentials: %s", strerror(errno));
        close(fd);
        return false;
    }
    username[user_len] = '\0'; // Potential Out-of-Bounds Write
    password[pass_len] = '\0'; // Potential Out-of-Bounds Write
    if (!verify_credentials(creds, username, password)) { // Function to verify the credentials
        logger(LOG_ERR, "Invalid credentials provided");
        close(fd);
        return false;
    }
    return true;
}