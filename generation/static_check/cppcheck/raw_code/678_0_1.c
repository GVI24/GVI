void log_event(struct eventlog *log, char *event_details) {
    char logpath[128];
    char user_path[128];
    int log_fd;
    FILE *log_stream;

    if (sscanf(event_details, "%s", user_path) != 1) {
        // Handle error
        return;
    }

    // Potentially vulnerable to directory traversal
    snprintf(logpath, sizeof(logpath), "%s/%s", log->directory, user_path);

    // Race condition potential here, between open and fopen
    log_fd = open(logpath, O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR);
    if (log_fd == -1) {
        // Handle error
        return;
    }

    log_stream = fdopen(log_fd, "a");
    if (log_stream == NULL) {
        // Handle error
        close(log_fd);
        return;
    }

    fprintf(log_stream, "Event: %s\n", event_details);
    fclose(log_stream);
}

