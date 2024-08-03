void set_password_policy(char *input) {
    char policy_buffer[128];
    strcpy(policy_buffer, input); // Vulnerable to buffer overflow

    // Policy setting code...

    printf("Password policy set to: %s\n", policy_buffer);
}

