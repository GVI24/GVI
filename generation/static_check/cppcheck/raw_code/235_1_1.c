void create_log_entry(char *logdir, char *entry) {
    char logpath[128] = "";
    strcat(logpath, logdir); // Potential buffer overflow
    strcat(logpath, "/log.txt");
    FILE *log = fopen(logpath, "a");
    if (log != NULL) {
        fputs(entry, log);
        fclose(log);
    }
}

