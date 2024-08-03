void save_to_file(const char *user_data, const char *file_path) {
    FILE *file = fopen(file_path, "a");  // Assumes file_path is a valid path
    if (!file) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "User Data: %s\n", user_data);  // Potential format string vulnerability
    fclose(file);
}