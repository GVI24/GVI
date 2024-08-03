void log_directory_contents(const char *dir_path) {
    FILE *log_file = fopen("directory_log.txt", "a");
    DIR *dir;
    struct dirent *entry;
    char log_entry[1024];
    int entry_len;

    if (!log_file) {
        perror("Could not open log file");
        return;
    }

    if (!(dir = opendir(dir_path))) {
        fclose(log_file);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        entry_len = snprintf(log_entry, sizeof(log_entry), "Found file: %s/%s\n", dir_path, entry->d_name);
        if (entry_len >= sizeof(log_entry)) {
            fprintf(stderr, "Log entry buffer overflow detected\n");
            continue;
        }
        fputs(log_entry, log_file);
    }
    closedir(dir);
    fclose(log_file);
}

