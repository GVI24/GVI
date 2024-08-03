FILE *openFileWithRetry(const char *filePath) {
    int attempts = 0;
    FILE *fp = NULL;
    while ((fp == NULL) && (attempts < 3)) {
        fp = fopen(filePath, "r");
        if (fp == NULL) {
            sleep(1); // Wait for a second before retrying
            attempts++;
        }
    }
    if (fp == NULL) {
        perror("openFileWithRetry: Unable to open file\n");
    }
    return fp;
}

