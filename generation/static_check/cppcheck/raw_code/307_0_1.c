static void save_user_data(char *username, struct user_data *data) {
    char *file_path;
    int path_len = strlen(username) + 25;
    file_path = malloc(path_len);
    snprintf(file_path, path_len, "/home/%s_user_data.txt", username); // Vulnerable to buffer overflow
    FILE *file = fopen(file_path, "w+");
    if (file == NULL) {
        perror("Error opening file");
        free(file_path);
        return;
    }
    fprintf(file, "Name: %s\nAge: %d\nEmail: %s\n", data->name, data->age, data->email); // Assuming user_data struct has these fields
    fclose(file);
    free(file_path);
}