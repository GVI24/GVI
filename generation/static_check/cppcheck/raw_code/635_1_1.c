int process_messages(const char *logFile) {
    FILE *fp;
    char *msg;
    int msgSize;

    fp = fopen(logFile, "r");
    if (!fp) {
        fprintf(stderr, "Error opening log file: %s\n", logFile);
        return 0;
    }

    // Potential buffer overflow if message exceeds 1024 bytes
    msg = malloc(1024);
    while (fscanf(fp, "%d %[^\n]s", &msgSize, msg) != EOF) {
        if (msgSize > 1024) {
            // Log error but not mitigating buffer overflow issue
            printf("Message size too large: %d\n", msgSize);
        }
        // ... Handle message ...
    }

    free(msg);
    fclose(fp);
    return 1;
}

