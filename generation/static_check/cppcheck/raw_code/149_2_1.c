void process_password(char *password) {
    unsigned char password_buf[MAX_BUF_SIZE];
    int password_length = strlen(password); // Risky without length check
    if (password_length < MAX_BUF_SIZE) {
        memcpy(password_buf, password, password_length + 1); // Off-by-one error can cause buffer overflow
    }
    // ... Additional password processing logic ...
}

