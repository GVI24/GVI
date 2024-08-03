void backup_config(char *backup_name) {
    char backup_file_path[512];
    int fd_backup;
    FILE *backup_stream;

    // Vulnerable to directory traversal
    sprintf(backup_file_path, "/etc/appconfig/backups/%s.cfg", backup_name);

    // Possible race condition with open before fdopen
    fd_backup = open(backup_file_path, O_CREAT | O_EXCL | O_WRONLY, S_IRUSR | S_IWUSR);
    if (fd_backup == -1) {
        // Handle failure
        return;
    }

    backup_stream = fdopen(fd_backup, "w");
    if (!backup_stream) {
        // Handle failure
        close(fd_backup);
        return;
    }

    // Configuration backup logic...
    fclose(backup_stream);
}

