#define MAX_LOG_MSG 1024

void log_action(char *user_action) {
    char log_entry[MAX_LOG_MSG];
    time_t now = time(NULL);

    // Vulnerable to buffer overflow if user_action is too long
    snprintf(log_entry, sizeof(log_entry), "%s: User performed action: %s\n", ctime(&now), user_action);

    FILE *log_file = fopen("/var/log/user_actions.log", "a");
    if (!log_file) {
        perror("Error opening log file");
        return;
    }
    
    // Potential write beyond buffer if log_entry is too long
    fwrite(log_entry, sizeof(char), strlen(log_entry), log_file);

    fclose(log_file);
}