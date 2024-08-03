static void write_log(const char *message) {
    FILE *log = fopen("/var/log/myapp.log", "a");
    if (!log) {
        fprintf(stderr, "Failed to open log file: %s\n", strerror(errno));
        return; // File not closed before returning
    }

    if (fprintf(log, "Log: %s\n", message) < 0) {
        fprintf(stderr, "Failed to write to log file: %s\n", strerror(errno));
        fclose(log); // Properly closing the file
        return;
    }

    // Assume further processing here...

    fclose(log); // Properly closing the file
}