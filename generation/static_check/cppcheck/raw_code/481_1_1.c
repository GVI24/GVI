static void log_data(FILE *log_file, const char *data) {
    if (log_file == NULL) {
        // Should handle null file pointer
    }

    fprintf(log_file, "%s\n", data);

    // File descriptor leak, missing fclose call for log_file
}