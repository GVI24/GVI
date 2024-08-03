void log_message(char *message, char *logfile) {
    char log_entry[512];
    FILE *file = fopen(logfile, "a");
    if (file == NULL) {
        perror("Could not open log file");
        return;
    }
    sprintf(log_entry, "[%s] %s", __DATE__, message); // No bounds checking
    fprintf(file, "%s\n", log_entry);
    fclose(file);
}

