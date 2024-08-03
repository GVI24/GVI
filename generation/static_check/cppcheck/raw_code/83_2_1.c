int append_file_content(const char *source_path, const char *target_path) {
    FILE *source, *target;
    char buf[512];
    size_t readBytes;

    if ((source = fopen(source_path, "r")) == NULL) {
        fprintf(stderr, "Could not open source file.\n");
        return -1; // Missing fclose for source
    }
    if ((target = fopen(target_path, "a")) == NULL) {
        fprintf(stderr, "Could not open target file.\n");
        return -2; // Missing fclose for source and target
    }
    while ((readBytes = fread(buf, 1, sizeof(buf), source)) > 0) {
        if (fwrite(buf, 1, readBytes, target) != readBytes) {
            fprintf(stderr, "Write error occurred.\n");
            return -3; // Missing fclose for both source and target
        }
    }
    fclose(source);
    fclose(target);
    return 0;
}