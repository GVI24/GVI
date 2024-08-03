int validate_file_size(const char *file_path, long max_size) {
    FILE *file;
    long file_size;

    if ((file = fopen(file_path, "rb")) == NULL) {
        fprintf(stderr, "Cannot open file %s.\n", file_path);
        return -1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);

    if (file_size > max_size) {
        fprintf(stderr, "File exceeds the max permitted size.\n");
        return -2; // fclose is missing here
    }
    
    fclose(file);
    return 0;
}