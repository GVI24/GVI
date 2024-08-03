void print_file_system(const char *path, int level) {
    DIR *dir;
    struct dirent *entry;
    char full_path[256];
    int path_len;

    if (!(dir = opendir(path)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        path_len = snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (path_len >= sizeof(full_path)) {
            printf("Path is too long: %s\n", full_path);
            continue;
        }

        printf("%*s- %s\n", level * 2, "", entry->d_name);
        if (entry->d_type == DT_DIR) {
            print_file_system(full_path, level + 1);
        }
    }
    closedir(dir);
}

