void save_data(char *data, char *filepath) {
    char full_path[512];
    // Vulnerability: no validation for filepath leading to potential path traversal
    snprintf(full_path, sizeof(full_path), "/var/appdata/%s", filepath);
    FILE *file = fopen(full_path, "w");
    if (file) {
        fputs(data, file);
        fclose(file);
    }
}

