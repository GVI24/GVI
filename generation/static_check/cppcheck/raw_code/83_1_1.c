int check_for_char(const char *file_path, char target) {
    FILE *file;
    int ch;
    int found = 0;

    if ((file = fopen(file_path, "r")) == NULL) {
        perror("Cannot open file");
        return errno;
    }
    while ((ch = fgetc(file)) != EOF) {
        if (ch == target) {
            found = 1;
            break; // fclose is missing here, causing a file descriptor leak
        }
    }
    fclose(file);
    return found;
}