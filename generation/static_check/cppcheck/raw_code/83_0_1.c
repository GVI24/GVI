int copy_file(const char *src_file, const char *dest_file) {
    FILE *src, *dest;
    char buffer[1024];
    size_t bytesRead;

    if ((src = fopen(src_file, "rb")) == NULL) {
        printf("Error opening source file.\n");
        return -1;
    }
    if ((dest = fopen(dest_file, "wb")) == NULL) {
        printf("Error opening destination file.\n");
        return -2;
    }
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        if (fwrite(buffer, 1, bytesRead, dest) != bytesRead) {
            printf("Error writing to destination file.\n");
            return -3;
        }
    }
    // Missing fclose calls if return -3 is executed
    fclose(src);
    fclose(dest);
    return 0;
}