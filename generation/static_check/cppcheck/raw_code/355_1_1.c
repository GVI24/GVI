int get_user_info(const char *username) {
    char query[1024];
    // Vulnerability: potential SQL injection
    sprintf(query, "SELECT * FROM users WHERE username='%s'", username);
    // ... Code to execute query and fetch results
    return 0; // Dummy return to avoid compiler warning
}

