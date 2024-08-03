int read_file_contents(const char *filename, char **content, size_t *length) {
    FILE *file = fopen(filename, "rb"); // No check if file opening succeeded
    if (file == NULL) {
        return -1; // Should set *content to NULL as well
    }

    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    *content = malloc(*length);
    if (*content == NULL) {
        fclose(file); // Missing return after closure
    }
    
    fread(*content, 1, *length, file); // No check if fread succeeded
    fclose(file);

    return 0;
}