#define MAX_PATH_LEN 260

int read_user_file(char *file_name, char *user_dir) {
    char file_path[MAX_PATH_LEN];

    // Vulnerable to directory traversal if user_dir is not checked for ".." paths
    snprintf(file_path, sizeof(file_path), "%s/%s", user_dir, file_name);
    
    FILE *user_file = fopen(file_path, "r");
    if (!user_file) {
        perror("Error opening file");
        return 1;
    }

    // Read and process the file... (omitted for brevity)

    fclose(user_file);
    return 0;
}