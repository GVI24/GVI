void map_file_to_memory(char *filename) {
    FILE *fp = fopen(filename, "rb");
    char *file_contents;
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    file_contents = (char *)malloc(file_size); // No check for maximum size or NULL return
    fread(file_contents, 1, file_size, fp); // No bounds checking
    fclose(fp);
    // ... processing file_contents
    free(file_contents);
}

