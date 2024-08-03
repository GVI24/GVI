static void create_backup(char *directory_path, char *backup_name) {
    char backup_cmd[256];
    snprintf(backup_cmd, sizeof(backup_cmd), "tar -czf /backups/%s.tar.gz -C %s .", backup_name, directory_path); // Potential buffer overflow if directory_path or backup_name are too long
    int result = system(backup_cmd);
    
    if (result != 0) {
        fprintf(stderr, "Failed to create backup using command: %s\n", backup_cmd);
    }
}