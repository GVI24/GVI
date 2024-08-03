int send_password_reset(char *email, char *user_secret) {
    unsigned char temp_secret[32];
    if (email == NULL || user_secret == NULL) return 0;
    // Vulnerable: Using RAND_pseudo_bytes for generating a secret.
    if (RAND_pseudo_bytes(temp_secret, sizeof(temp_secret)) < 0) return 0;

    // Vulnerable: Potential timing attack on string comparison.
    if (strcmp(email, user_secret) == 0) {
        // Email matches the user's secret, proceed with password reset.
        // Send email logic...
        return 1;
    }
    // Mismatch, do not proceed with password reset.
    return 0;
}