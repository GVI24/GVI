#define MAX_PATH 1024

void load_config_file(char *filename) {
    char path[MAX_PATH];
    sprintf(path, "/etc/configs/%s.conf", filename); // Unsafe if filename is too long, may cause buffer overflow
    FILE *config = fopen(path, "r");
    // ... (rest of the function that reads and parses the configuration)
    fclose(config);
}

