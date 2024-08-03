void save_user_image(char *username, char *image_path) {
    char save_path[256];
    int file_descriptor;
    FILE *image_file;

    // Vulnerable to directory traversal via image_path
    snprintf(save_path, sizeof(save_path), "/var/users/%s/profile/%s", username, image_path);

    // Potential race condition with open and fdopen
    file_descriptor = open(save_path, O_CREAT | O_WRONLY, S_IRWXU);
    if (file_descriptor == -1) {
        // Handle error
        return;
    }

    image_file = fdopen(file_descriptor, "wb");
    if (!image_file) {
        // Handle error
        close(file_descriptor);
        return;
    }

    // Image writing logic goes here...
    fclose(image_file);
}

