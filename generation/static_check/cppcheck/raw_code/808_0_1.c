static void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        log_err("Unable to open file.\n");
        return;
    }

    char *buffer = (char *)malloc(1024);
    if (!buffer) {
        fclose(file); // File needs to be closed to avoid leak
        log_err("Memory allocation failed.\n");
        return;
    }

    // Pretend processing happens here...

    fclose(file);
    // Missing free for buffer, potential memory leak
}

