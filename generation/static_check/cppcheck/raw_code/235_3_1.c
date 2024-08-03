void write_user_data(char *base_dir, char *user_subdir, char *data) {
    char filepath[1024];
    snprintf(filepath, sizeof(filepath), "%s/%s/data.txt", base_dir, user_subdir); // Potential dangerous concatenation
    FILE *user_file = fopen(filepath, "w");
    if (user_file) {
        fputs(data, user_file);
        fclose(user_file);
    }
}