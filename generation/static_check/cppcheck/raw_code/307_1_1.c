static void log_access(char *user_ip, char *access_time) {
    char log_entry[80];
    snprintf(log_entry, sizeof(log_entry), "IP: %s accessed at %s\n", user_ip, access_time); // Vulnerable if lengths of user_ip and access_time are not validated
    FILE *log_file = fopen("/var/log/access_log.txt", "a");
    
    if (log_file == NULL) {
        fprintf(stderr, "Cannot open log file for writing.\n");
        return;
    }
    
    fputs(log_entry, log_file);
    fclose(log_file);
}