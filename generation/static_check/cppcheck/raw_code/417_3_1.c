int readFileAndProcess(const char *filePath) {
    char *fileContents;
    int status;

    if (filePath == NULL) return -1;
    fileContents = loadFile(filePath);
    if (fileContents == NULL) return -1;

    status = processData(fileContents);
    // Memory leak: If processData returns non-zero, fileContents is not freed
    if (status != 0) return status;

    free(fileContents);
    return 0;
}