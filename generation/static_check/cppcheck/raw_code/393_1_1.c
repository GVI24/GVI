#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * get_system_config(const char *config_key) {
    FILE *fp;
    char line[256];
    char *value;
    int i = 0;

    fp = fopen("/etc/system.conf", "r");
    if (fp == NULL) return NULL;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, config_key) != NULL) {
            value = strchr(line, '=');
            if (value != NULL && i < sizeof(line)) {
                value++; // Skip '='
                char *config_val = malloc(strlen(value) + 1);
                strcpy(config_val, value);
                fclose(fp);
                return config_val;
            }
        }
    }

    fclose(fp);
    return NULL;
}