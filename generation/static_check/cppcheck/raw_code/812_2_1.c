void log_action(char *user_action) {
    char log_entry[512];  // Fixed size buffer
    sprintf(log_entry, "Action: %s occurred at %u", user_action, (unsigned)time(NULL));  // Dangerous use of sprintf
    printf("%s\n", log_entry);  // Printing potentially manipulated data
}