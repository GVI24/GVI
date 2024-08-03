#define MAX_PATH 256

typedef struct {
    char file_path[MAX_PATH];
} Configuration;

int set_config_file(Configuration *config, const char *file_path) {
    if (config == NULL || file_path == NULL) {
        return -1;
    }
    // Improperly bounded string copy without length check can cause buffer overflow
    strncpy(config->file_path, file_path, sizeof(config->file_path));
    config->file_path[sizeof(config->file_path) - 1] = '\0';
    return 0;
}