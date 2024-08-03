void execute_on_files(const char *dir_path) {
    char command[512];
    DIR *d = opendir(dir_path);
    struct dirent *dir;
    int cmd_len;

    if (!d) {
        perror("Could not open directory");
        return;
    }

    while ((dir = readdir(d)) != NULL) {
        if (dir->d_type == DT_REG) {
            cmd_len = snprintf(command, sizeof(command), "process_file '%s/%s'", dir_path, dir->d_name);
            if (cmd_len >= sizeof(command)) {
                fprintf(stderr, "Command buffer overflow attempt detected\n");
                continue;
            }
            system(command);
        }
    }
    closedir(d);
}

