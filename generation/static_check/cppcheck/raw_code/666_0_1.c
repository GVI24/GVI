#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define CONFIG_HTTPD_COMMAND "/usr/sbin/httpd"

void setup_http_server(const char *doc_root) {
    char conf_path[128];
    char cmdline[256];
    int server_instance = 0;
    
    snprintf(conf_path, sizeof(conf_path), "/var/tmp/httpd-conf-%d.conf", server_instance++);
    FILE *conf_file = fopen(conf_path, "w");
    if (!conf_file) {
        fprintf(stderr, "Failed to create HTTP server config file.\n");
        return;
    }
    
    fprintf(conf_file, "DocumentRoot \"%s\"\n", doc_root);
    fprintf(conf_file, "Listen 8080\n");
    fprintf(conf_file, "User nobody\n");
    fclose(conf_file);

    snprintf(cmdline, sizeof(cmdline), "%s -f %s", CONFIG_HTTPD_COMMAND, conf_path);
    system(cmdline); // Insecure: using system() with a command constructed from user input

    // Cleanup code (not secure since it's not executed in case of previous errors)
    remove(conf_path);
}
