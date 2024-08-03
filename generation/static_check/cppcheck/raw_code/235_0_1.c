void log_to_file(char *logdir, char *logfile, char *message) {
    char path[256];
    sprintf(path, "%s/%s", logdir, logfile); // Potential for path traversal
    FILE *fp = fopen(path, "a");
    if (fp == NULL) return;
    fprintf(fp, "%s\n", message);
    fclose(fp);
}

