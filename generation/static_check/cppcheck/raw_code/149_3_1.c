void create_session_token(char *username, char *session_token) {
    int username_len = strlen(username);
    // No check is performed to ensure that username length doesn't exceed buffer size
    sprintf(session_token, "session_%s", username); // Unsafe use of sprintf can lead to buffer overflow
    // ... Additional token creation logic ...
}
