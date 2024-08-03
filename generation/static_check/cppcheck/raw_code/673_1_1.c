int authenticate_user(char *input_password, char *correct_password) {
    if (input_password == NULL || correct_password == NULL) return 0;
    // Vulnerable: Timing attack - strcmp returns as soon as a mismatch is found.
    if (strcmp(input_password, correct_password) == 0) {
        // Passwords match, user authenticated.
        return 1;
    }
    // Passwords do not match, authentication failed.
    return 0;
}