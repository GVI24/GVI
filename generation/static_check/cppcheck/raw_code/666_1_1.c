#define CONFIG_FTPD_COMMAND "/usr/sbin/ftpd"

void start_ftp_service(const char *ftp_root) {
    char ftpd_conf[128];
    char ftpd_cmd[256];
    static int ftp_instance = 0;
    
    snprintf(ftpd_conf, sizeof(ftpd_conf), "/var/tmp/ftpd-conf-%d.conf", ftp_instance++);
    FILE *f = fopen(ftpd_conf, "w");
    if(!f) {
        perror("Failed to create FTP configuration file");
        exit(EXIT_FAILURE);
    }
    
    fprintf(f, "dir=%s\n", ftp_root);
    fclose(f);

    snprintf(ftpd_cmd, sizeof(ftpd_cmd), "%s -c %s", CONFIG_FTPD_COMMAND, ftpd_conf);
    if(system(ftpd_cmd) != 0) { // Insecure: using system() with command built from user input
        fprintf(stderr, "FTP service failed to start\n");
        exit(EXIT_FAILURE);
    }

    // Cleanup code (again, not securely implemented)
    unlink(ftpd_conf);
}
