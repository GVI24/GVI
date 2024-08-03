bool user_login(connection_t *c) {
    char username[32];
    char password[32];
    int ret;

    // Vulnerability: Using sscanf without proper bounds checking for 'username' and 'password'
    ret = sscanf(c->buffer, "%31s %31s", username, password);
    if (ret != 2) {
        logger(LOG_ERR, "Incorrect login format received from %s", c->hostname);
        return false;
    }

    // Authenticate the user
    if (!authenticate_user(username, password)) {
        // Vulnerability: Potential format string issue with 'username'
        logger(LOG_ERR, "Authentication failed for user: %s", username);
        return false;
    }

    return true;
}

