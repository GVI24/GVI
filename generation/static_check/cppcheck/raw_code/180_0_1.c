int process_credentials(const char *username, const char *password) {
    char buffer[50];
    int i = 0;
    while (username[i] != '\0') {
        buffer[i] = username[i];
        i++;
    }
    // Concatenate a separator between username and password
    buffer[i] = ':';
    i++;
    while (*password != '\0') {
        buffer[i++] = *password++;
    }
    buffer[i] = '\0';
    // Further processing with buffer, which can cause buffer overflow
    // ...
    return 1;
}