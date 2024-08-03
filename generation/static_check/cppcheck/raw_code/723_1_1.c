void log_policy_change(const char *user, const char *log_message) {
    // Log message should be a controlled format, but directly uses user input
    printf(log_message); // Vulnerable to format string attacks

    // Log handling code...

    printf("%s changed the policy.\n", user);
}

